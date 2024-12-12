//see courses_description.txt for problem

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student{
    char* username;
    int id;
    int section;
    int* assignments;
    int* midterms;
    int final_grade;
    struct student* next; 
};

struct studlist{
    struct student* head;
};

struct instructor{
    char* name;
    int section;
    struct instructor* next;
};

struct instlist{
    struct instructor* head;
};

typedef struct{
    struct studlist* s;
    struct instlist* i;
}course;

course* createcourse(){
    course* c = malloc(sizeof(course));
    struct studlist* s = malloc(sizeof(struct studlist));
    s->head = NULL;
    struct instlist* i = malloc(sizeof(struct instlist));
    i->head = NULL;
    c->s = s;
    c->i = i;
    return c;
}

void deletecourse(course* c){
    struct studlist* s = c->s;
    struct instlist* i = c->i;

    struct student* stemp = s->head;
    while(s->head){
        s->head = stemp->next;
        free(stemp->assignments);
        free(stemp->midterms);
        free(stemp);
        stemp = s->head;
    }
    free(s);
    s=NULL;

    struct instructor* itemp = i->head;
    while(i->head){
        i->head = itemp->next;
        free(itemp);
        itemp = i->head;
    }
    free(i);
    i=NULL;

    free(c);
    c=NULL;
}

void addstudent(course* c, char* username, int id, int section){
    struct student* s = malloc(sizeof(struct student));
    s->username = username;
    s->id = id;
    s->section = section;
    //default grades to 0
    s->assignments = calloc(10,sizeof(int));
    s->midterms = calloc(3,sizeof(int));
    s->final_grade = 0;

    struct studlist* slist = c->s;
    s->next = slist->head;
    slist->head = s;
}

void addinstructor(course* c, char* name, int section){
    struct instructor* i = malloc(sizeof(struct instructor));
    i->name = name;
    i->section = section;

    struct instlist* ilist = c->i;
    i->next = ilist->head;
    ilist->head = i;
}

void removestudent(course* c, int id){
    struct studlist* slist = c->s;
    struct student* current = slist->head;
    struct student* prev = slist->head;

    while(current){
        if(current->id == id){
            //only possible on if curr is first in list
            if(prev == current){
                slist->head = current->next;
            }else{
                prev->next = current->next;
            }
            free(current->assignments);
            free(current->midterms);
            free(current);
            break;
        }
        prev = current;
        current = current->next;
    }
}

//pre: valid assignment_number (0-9)
void addassignment(course* c, char* username, int assignment_number, int grade){
    struct studlist* s = c->s;
    struct student* current = s->head;
    while(current){
        if(strcmp(username, current->username)==0){
            current->assignments[assignment_number] = grade;
        }
        current = current->next;
    }
}

//pre: valid midterm_number (0-2)
void addmidterm(course* c, char* username, int midterm_number, int grade){
    struct studlist* s = c->s;
    struct student* current = s->head;
    while(current){
        if(strcmp(username, current->username)==0){
            current->midterms[midterm_number] = grade;
        }
        current = current->next;
    }
}

void updategrade(course* c, char* username){
    struct studlist* s = c->s;
    struct student* current = s->head;
    while(current){
        if(strcmp(username, current->username)==0){
            double sum = 0;
            for(int i=0;i<10;i++){
                sum+=current->assignments[i];
            }
            double pregrade = 0.4*(sum/10.0);

            for(int i=0;i<3;i++){
                pregrade+=(0.2*current->midterms[i]);
            }

            current->final_grade = (int) pregrade;
        }
        current = current->next;
    }
}

//unsorted print for now
void printgrades(course* c){
    struct studlist* s = c->s;
    struct student* curr = s->head;

    while(curr){
        printf("username: %s, final grade: %d\n",curr->username,curr->final_grade);
        curr = curr->next;
    }
}

void printfails(course* c, int section){

    struct studlist* s = c->s;
    struct student* curr = s->head;
    printf("Failed students in section %d:\n", section);
    int count = 0;
    while(curr){
        if(curr->final_grade < 50 && curr->section == section) {
            printf("username: %s\n",curr->username);
            count++;
        }
        curr = curr->next;
    }
    if (count == 0) printf("N/A\n");
}

int main(void){
    //create a course
    course* c = createcourse();

    //add instructors
    addinstructor(c, "Smith", 101);
    addinstructor(c, "Johnson", 102);
    addinstructor(c, "Brown", 103);

    //add students to different sections
    addstudent(c, "Alice", 1, 101);
    addstudent(c, "Bob", 2, 102);
    addstudent(c, "Charlie", 3, 103);
    addstudent(c, "Diana", 4, 101);
    addstudent(c, "Eve", 5, 102);

    //assign grades for all 10 assignments and 3 midterms
    //Alice
    for (int i = 0; i < 10; i++) {
        addassignment(c, "Alice", i, 85 + (i % 5));
    }
    for (int i = 0; i < 3; i++) {
        addmidterm(c, "Alice", i, 90 + (i % 2));
    }

    //Bob
    for (int i = 0; i < 10; i++) {
        addassignment(c, "Bob", i, 60 - (i % 5));
    }
    for (int i = 0; i < 3; i++) {
        addmidterm(c, "Bob", i, 50 - (i % 3));
    }

    //Charlie
    for (int i = 0; i < 10; i++) {
        addassignment(c, "Charlie", i, 40 + (i % 3));
    }
    for (int i = 0; i < 3; i++) {
        addmidterm(c, "Charlie", i, 45 + (i % 2));
    }

    //Diana
    for (int i = 0; i < 10; i++) {
        addassignment(c, "Diana", i, 95 - (i % 4));
    }
    for (int i = 0; i < 3; i++) {
        addmidterm(c, "Diana", i, 90 + (i % 3));
    }

    //Eve
    for (int i = 0; i < 10; i++) {
        addassignment(c, "Eve", i, 30 + (i % 6));
    }
    for (int i = 0; i < 3; i++) {
        addmidterm(c, "Eve", i, 25 + (i % 4));
    }

    //update grades
    updategrade(c, "Alice");
    updategrade(c, "Bob");
    updategrade(c, "Charlie");
    updategrade(c, "Diana");
    updategrade(c, "Eve");

    //print all grades
    printf("All Grades:\n");
    printgrades(c);

    //print students who failed in each section
    printf("\nFailures by section:\n");
    printfails(c, 101);
    printfails(c, 102);
    printfails(c, 103);

    //remove students and check integrity
    printf("\nRemoving Alice (ID 1) and Eve (ID 5):\n");
    removestudent(c, 1);
    removestudent(c, 5);
    printf("Updated Grades After Removal:\n");
    printgrades(c);

    //add a new student
    printf("\nAdding Fred (ID 6) to section 101:\n");
    addstudent(c, "Fred", 6, 101);
    for (int i = 0; i < 10; i++) {
        addassignment(c, "Fred", i, 100 - (i % 2));
    }
    for (int i = 0; i < 3; i++) {
        addmidterm(c, "Fred", i, 95 - (i % 3));
    }
    updategrade(c, "Fred");
    printgrades(c);

    deletecourse(c);
    printf("\nCourse data cleared\n");

    return 0;
}