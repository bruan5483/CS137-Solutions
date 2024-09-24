#include <stdio.h>
int main(void){
    int num_people, slices_per_pizza, slices_each;
    scanf("%d %d %d", &num_people, &slices_per_pizza, &slices_each);

    int slices_needed = num_people*slices_each;

    if (slices_needed % slices_per_pizza == 0){
        printf("%d\n", slices_needed/slices_per_pizza);
    } else printf("%d\n", slices_needed/slices_per_pizza + 1);

    return 0;
}