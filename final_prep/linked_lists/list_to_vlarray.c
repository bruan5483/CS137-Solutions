//Practice how to convert values stored in a list into a dynamically allocated array and vice versa
//Doing it for integers

#include <stdio.h>
#include <stdlib.h>

struct lnode{
    int value;
    struct lnode* next;
};

struct intlist{
    struct lnode* head;
};

struct intlist* create(){
    struct intlist *new = malloc(sizeof(struct intlist));
    new->head = NULL;
    return new;
}

void destroy(struct intlist* det){
    struct lnode* curr = det->head;
    while(curr){
        det->head = curr->next;
        free(curr);
        curr = det->head;
    }
    free(det);
    det = NULL;
}

//just add to back
void add(struct intlist* start, int value){
    struct lnode* new  = malloc(sizeof(struct lnode));
    new->value = value;

    if(!start->head){
        new->next = start->head;
        start->head = new;
    } else {
        struct lnode* curr = start->head;
        while(curr->next){
            curr = curr->next;
        }
        new->next = curr->next;
        curr->next = new;
    }
}

//pre: len>0
int *convert_to_array(struct intlist*det){
    int *vlarray = malloc(sizeof(int));

    struct lnode* curr = det->head;
    int len = 1;
    while(curr){
        vlarray = realloc(vlarray, len*sizeof(int));
        vlarray[len-1] = curr->value;
        curr = curr->next;
        len++;
    }
    return vlarray;
}

struct intlist* convert_to_list(int* array, int len){
    struct intlist* ret = create();
    for(int i=0; i<len; i++){
        add(ret, array[i]);
    }
    return ret;
}

void printlist(struct intlist* l){
    struct lnode* curr = l->head;
    printf("list: ");
    while(curr){
        printf("%d ",curr->value);
        curr = curr->next;
    }
    printf("\n");
}

int main(void){
    struct intlist* test = create();
    add(test, 5);
    add(test, 4);
    add(test, 3);
    add(test, 2);
    add(test, 1);
    add(test, 0);
    add(test, -1);

    printf("og ");
    printlist(test);

    int *array = convert_to_array(test);
    printf("array: ");
    for (int i=0; i<7; i++) printf("%d ", array[i]);
    printf("\n");

    struct intlist* temp = convert_to_list(array, 7);
    printf("new ");
    printlist(temp);

    free(array);
    destroy(temp);
    destroy(test);
    return 0;
}