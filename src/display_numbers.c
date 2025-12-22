#include <stdio.h>
#include "../modules.h"

/*
* ==============================
* Purpose
* ==============================
* Display a set of real numbers
* ==============================
*
* ==============================
* Description
* ==============================
* display_numbers() is a subsystem of the Sort Real numbers system
* This module is responsible to display the set of inputs
*
* ==============================
* Requirementes
* ==============================
* A collection of real numbers produced by the input subsystem (FR-1)
*
* ==============================
* Inputs
* ==============================
* @numbers - A constant float array that contains input values
* @limit   - Maximum numbers of elements in @numbers
*
* ==============================
* Process
* ==============================
* Print 10 values per line
*
* ==============================
* Output
* ==============================
* Each element in @numbers is printed
* None return value
*
* ==============================
* Execution flow
* ==============================
* Declare variable
*   @index - An integer variable, it stores increment value for count-controlled loop
*
* Condition loop:
*   @index < @limit
*
* Execution step:
*   For each elements:
*      - print its value to the user.
*      - Evaluate if @index % 10 == 9, true print a newline
*
* Condition @index % 10 != 0
*      - Print a newline
*
* ==============================
* Module dependency
* ==============================
* None
*
* ==============================
* Library dependency
* ==============================
* stdio.h - standard input / output
*/

void display_numbers(const float numbers[], const int limit){
    int index = 0;
    for(index = 0; index < limit; index++){
        printf("%.2f",  numbers[index]);
        if(index % 10 == 9)
            printf("\n");
    }
    if(index % 10 != 0)
        printf("\n");
}
