#include <stdio.h>
#include "../modules.h"
void display_numbers(const float numbers[], const int limit){
    for(int index = 0; index < limit; index++)
        printf("%.2f\n",  numbers[index]);
}
