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
*   - Sort them in ascending order FR-2
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
* ==============================
* Inputs:
* ==============================
*       - Set of real numbers provided by the user. FR-1
*
* ==============================
* Process
* ==============================
*   - Sort them in ascending order FR-2
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
#include "modules.h"
#define MAX 100

int main(void){
    float listOfNumbers[MAX];
    int count = 0;

    count = get_set_of_numbers(listOfNumbers, MAX);
    if(count > 0){
        printf("\n----------Details-------------\n");
        printf("\nOriginal input numbers\n");
        display_numbers(listOfNumbers, count);
        sort_real_numbers(listOfNumbers, count);
        printf("\nSorted input numbers\n");
        display_numbers(listOfNumbers, count);
        printf("\n------------End---------------\n");
    }else{
        puts("No data entered");
    }

    return 0;
}




