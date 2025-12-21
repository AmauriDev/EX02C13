#include <stdio.h>
#include "../modules.h"
int get_set_of_numbers(float numbers[], const int limit){
    int count = 0;

    for(count = 0; count < limit; count++){
        printf("Enter numbers left: %d\n", limit - count);
        scanf("%f", &numbers[count]);
    }

    return count;
}
