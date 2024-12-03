#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Person{
    int id;
    int speed;
    struct Person* next;
}Person;

Person updatePerson(int id, int speed){
    Person update;
    update.id = id;
    update.speed = speed;
    update.next = NULL;
    return update;
}

void addPerson(Person** start, Person* new) {
    if (!*start){
        new->next = new;
        *start = new;
    } else {
        new->next = *start;
        Person* temp = *start;
        while (temp->next != *start) {
            temp = temp->next;
        }
        temp->next = new;
    }
}


// Returns the winner
Person* play(Person* start) {

    //find the final person in the circle next to start
    Person* final = start;
    int circle_size = 0;
    while(final->next != start){
        final = final->next;
        circle_size++;
    }
    //printf("%d\n",final->id);
    //take start out of the circle
    final->next = start->next;
    
    while(circle_size>0){
        Person* current = start->next;
        for(int i = 0; i < start->id; i++){
           printf("%d duck %d\n",start->id,current->id);
           final = current;
           current = current->next;
        }
        printf("%d goose! %d\n",start->id,current->id);

        final->next = current->next;    

        if(start->speed > current->speed){
            Person* temp = current;
            current = current->next;
            if (start->next == temp) start->next = temp->next;
            free(temp);
        } else {
            Person* temp = start;
            start = current;
            free(temp);
        }
        circle_size--;
    }
    
    printf("winner! %d\n", start->id);
    return start;
}

int main(){
    int p, s;

    // List of people
    Person* lop = NULL;

    // Read in participants
    while (scanf("%d %d", &p, &s) == 2){
        Person* np = (Person*)malloc(sizeof(Person));
        *np = updatePerson(p, s);
        addPerson(&lop, np);
    }

    Person* winner = play(lop);
    free(winner);
}
