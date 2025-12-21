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
* Print values
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
* For each: @index < @limit
*   - Print @numbers element
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
    for(int index = 0; index < limit; index++)
        printf("%.2f\n",  numbers[index]);
}
