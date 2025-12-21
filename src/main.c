/*
* ==============================
* Sort real numbers
* ==============================
*
* ==============================
* Purpose
* ==============================
*   - Sort a set of real numbers,
*   - The system allows the user to enter a set of real numbers
*   - Sort them and display sorted result
*
* ==============================
* Inputs:
* ==============================
*       - Set of real numbers provided by the user. FR-1
*
* ==============================
* Process
* ==============================
*   - Sort them in asceding order FR-2
*
* ==============================
* Output
* ==============================
*   - Sorted result FR-3
*
/*
* ==============================
* Sort real numbers
* ==============================
*
* ==============================
* Purpose
* ==============================
*   - Sort a set of real numbers,
*   - The system allows the user to enter a set of real numbers
*   - Sort them and display sorted result
*
*
* ==============================
* Inputs:
* ==============================
*       - Set of real numbers provided by the user. FR-1
*
* ==============================
* Process
* ==============================
*   - Sort them in asceding order FR-2
*
* ==============================
* Output
* ==============================
*   - Sorted result FR-3
*
* ==============================
* Execution flow
* ==============================
*   1. Prompt for a set of real numbers FR-1
*   2. Validate: If count > 0 , continue: Else display message and exit
*   3. Display original number with header FR-3
*   4. Sort them in ascending order FR-2
*   5. Display sorted result with header FR-3
*   6. Exit the program
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 10
void display_numbers(const float numbers[], const int limit);
void sort_real_numbers(float numbers[], const int limit);
int get_set_of_numbers(float numbers[], const int limit);
void swap(float *a, float *b);

int main(void){
    float listOfNumbers[MAX];
    int count = 0;

    count = get_set_of_numbers(listOfNumbers, MAX);
    if(count > 0){
        puts("Original input numbers");
        display_numbers(listOfNumbers, MAX);
        sort_real_numbers(listOfNumbers, MAX);
        puts("Sorted input numbers");
        display_numbers(listOfNumbers, MAX);
    }else{
        puts("No data entered");
    }

    return 0;
}

int get_set_of_numbers(float numbers[], const int limit){
    int count = 0;

    for(count = 0; count < limit; count++){
        printf("Enter numbers left: %d\n", limit - count);
        scanf("%f", &numbers[count]);
    }

    return count;
}

void sort_real_numbers(float numbers[], const int limit){
    int i, j, next, current;

    for(i = 0; i < limit - 1; i++){
        for(j = 0; j < limit - (1 + i); j++){
            next = j + 1;
            current = j;
            if(numbers[current] > numbers[next]){
                swap(&numbers[current], &numbers[next]);
            }
        }
    }
}

void swap(float *a, float *b){
    float temp = 0.0;
    temp = *a;
    *a = *b;
    *b = temp;
}

void display_numbers(const float numbers[], const int limit){
    for(int index = 0; index < limit; index++)
        printf("%.2f\n",  numbers[index]);
}