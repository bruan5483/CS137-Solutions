#include "bank.h"

Bank* CreateBank(double money, double maxLoan,
                    double loanInterest, double transferFeeRate) {
    // Allocate bank
    Bank *bank = malloc(sizeof(Bank));
    assert(bank);
    // No accounts yet
    bank->accounts = NULL;
    bank->nAcc = 0;
    // Assign inputs
    bank->money = money;
    bank->maxLoan = maxLoan;
    bank->loanInterest = loanInterest;
    bank->transferFeeRate = transferFeeRate;

    return bank;
}

Account* OpenAccount(Bank *bank) {
    Account *acc = malloc(sizeof(Account));
    assert(acc);

    assert(bank);
    bank->nAcc += 1;

    acc->id = bank->nAcc;
    acc->active = true;
    acc->balance = 0.0;
    acc->bank = bank;
    acc->loan = (Loan){false, 0.0, 1.0};

    Account **p = malloc(bank->nAcc*sizeof(Account*));
    assert(p);
    for(int i=0;i< bank->nAcc-1;i++){
        p[i] = (bank->accounts)[i];
    }
    p[bank->nAcc-1] = acc;
    free(bank->accounts);
    bank->accounts = p;

    return acc;
}

void Deposit(double amount, Account *account) {
    assert(account);
    if(account->active) account->balance+=amount;
    return;
}

bool Withdraw(double amount, Account *account) {
    assert(account);
    if(!account->active) return false;
    if (amount > account->balance) return false;
    account->balance -= amount;
    return true;
}

bool TakeLoan(double amount, Account *account) {
    assert(account);
    if(!account->active || account->loan.active) return false;
    assert(account->bank);
    if(amount > (account->bank)->maxLoan || amount > (account->bank)->money) return false;
    account->loan = (Loan){true, amount, (account->bank)->loanInterest};
    account->balance += amount;
    (account->bank)->money -= amount;
    return true;
}

bool PayLoan(Account *account) {
    assert(account);
    if(!account->active || !account->loan.active) return true;
    double pay = account->loan.amount * account->loan.interest;
    if(account->balance < pay) return false;
    account->balance -= pay;
    assert(account->bank);
    (account->bank)->money += pay;
    account->loan = (Loan){false, 0.0, 1.0};
    return true;
}

bool Transfer(double amount, Account *sender, Account *receiver) {
    assert(sender);
    assert(receiver);
    if(!sender->active || !receiver->active) return false;
    assert(sender->bank);
    assert(receiver->bank);
    if(sender->bank != receiver->bank){
        double pay = amount * (sender->bank)->transferFeeRate;
        if(!Withdraw(amount + pay, sender)) return false;
        (sender->bank)->money += pay;
    } else {
        if(!Withdraw(amount, sender)) return false;
    }
    Deposit(amount, receiver);
    return true;
}

bool CollectLoanPayments(Bank *bank) {
    bool fail = false;
    for(int i=0; i < bank->nAcc; i++){
        if(!PayLoan(bank->accounts[i])) fail = true;
    }
    return !fail;
}

bool CloseAccount(Account *account) {
    assert(account);
    if(!account->active) return true;
    if(!PayLoan(account)) return false;
    account->active = false;
    account->balance = 0;
    return true;
}

Bank* ForceDestroyBank(Bank *bank) {
    // Check if bank exists
    if (!bank)
        return NULL;
    // Just free the memory
    for (int i = 0; i < bank->nAcc; i++) {
                  free(bank->accounts[i]);
    }
    free(bank->accounts);
        
    free(bank);
    bank = NULL;
    return NULL;
}

void ShowAccount(Account *account) {
    printf("Account #%d:\n", account->id);
    if (account->active) {
        printf("Balance: %.3f\n", account->balance);
        if (account->loan.active) {
            printf("Loaned %.3f with interest %f\n",
                account->loan.amount, account->loan.interest);
        }
    } else {
        printf("Inactive account\n");
    }
}

void ShowBank(Bank *bank) {
    printf("BANK:\n");
    printf("Total money in bank: %.3f\n", bank->money);
    printf("Maximum loan offered: %.3f\n", bank->maxLoan);
    printf("Interest for loans: %f\n", bank->loanInterest);
    printf("Fee for a money transfer: %f\n", bank->transferFeeRate);
    //printf("----------------\n");
    for (int i = 0; i < bank->nAcc; i++) {
        ShowAccount(bank->accounts[i]);
        printf("----------------\n");
    }
}

