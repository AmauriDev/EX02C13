#include "../modules.h"

/*
* ==============================
* Module - get_set_of_real_numbers()
* ==============================
*
* ==============================
* Purpose
* ==============================
*   Sort a set of real numbers
*   in ascending order
*
* ==============================
* sort_real_numbers is a subsystem of the Sort Real Numbers system.
* this module is responsible for reorder real numbers
*
* ==============================
* Requirements
* ==============================
*   A collection of real numbers
*   provided by the user FR-1
*
* ==============================
* Inputs:
* ==============================
*   - @numbers - A float array numbers
*   - @limit   - Maximum numbers of elements in @numbers
*
* ==============================
* Process
* ==============================
*   Reorder numbers
*
* ==============================
* Output
* ==============================
*   The sorted results are store in provided array
*   None return value
*
* ==============================
* Execution flow
* ==============================
*   - Declare the following variables:
*       @i - int variable for outer loop
*       @j - int variable for inner loop
*       @next - an int semantical variable to represent the next value
*       @current - an int semantical variable to represent current value
*
*   - For each @i to @limit - 1
*       - For each @j to @limit - (@i + 1)
*           Set @current = j
*           Set @next = current + 1
*           If current > next, swap current and next : continue
*
* ==============================
* Module dependency
* ==============================
* - swap() is a private module
*
* ==============================
* Library dependency
* ==============================
*   - NONE
*/
static void swap(float *a, float *b);
void sort_real_numbers(float numbers[], const int limit){
    int i, j, next, current;

    for(i = 0; i < limit - 1; i++){
        for(j = 0; j < limit - (1 + i); j++){
            current = j;
            next = current + 1;
            if(numbers[current] > numbers[next]){
                swap(&numbers[current], &numbers[next]);
            }
        }
    }
}

/*
* ==============================
* Module - swap()
* ==============================
*
* ==============================
* Purpose
* ==============================
* Change location of two real numbers
*
* ==============================
* Description
* ==============================
* swap() is a subsystem private to sort_real_numbers().
*
* ==============================
* Requirements
* ==============================
* Two real numbers
*
* ==============================
* Input:
* ==============================
* Both real numbers are provided by sort_real_numbers()
* @a - a float real numbers passed by reference
* @b - a float real numbers passed by reference
*
* ==============================
* Process
* ==============================
* Change location
*
* ==============================
* Execution flow
* ==============================
* Declare a float @temp variable
* Set @temp = @a
* Set @a = @b
* Set @b = @temp
*
* ==============================
* Output
* ==============================
* Both value are stored in its own variables passed by reference
* None return value
*
* ==============================
* Module dependency
* ==============================
* NONE
*
* ==============================
* Library dependency
* ==============================
* NONE
*
*/

static void swap(float *a, float *b){
    float temp = *a;
    *a = *b;
    *b = temp;
}
