#include <stdio.h>
#include <ctype.h>
#include "../modules.h"
/*
* ========================================
* Module - get_set_of_real_numbers()
* ========================================
*
*
* ========================================
* Purpose
* ========================================
* Collect a set of real numbers FR-1
*
* ========================================
* Description
* ========================================
* get_set_of_real_numbers is a subsystem 
* of the Sorting Real Numbers system
* This module is responsible to collect inputs
* from the user
*
* ========================================
* Requirements
* ========================================
* Real numbers provided by the user
*
*
* ========================================
* Inputs:
* ========================================
* @numbers - A float array to store each input provided by the user
* @limit - A constant integer set the maximum number of elements in @numbers
*
* ========================================
* Process
* ========================================
* Prompt to the user for real numbers and return the numbers of input entered
*
* ========================================
* Output
* ========================================
* The system provides feedback to the user by:
*   - Displaying instructions on how to enter a set of numbers and how to stop the input process.'
*   - Notifying whether each input is accepted or rejected
*
*   Accepted inputs:
*       - Valid real numbers.
*       - The character 'q' to stop execution flow of this module
*
*   Rejected inputs:
*       - Any input that is neither a valid real number not the character 'q'
*
*   - Notifying when the collection of numbers has reached its maximum limit.
*
* Return value:
*   - The total numbers of accepted real numbers.
*
*
* ========================================
* Execution flow
* ========================================
* Declare the following variables
*   @count   - An integer variable that stores the total number of accepted inputs and controls the loop condition.
*   @status  - An integer variable that stores the result returned by scanf()
*   @c       - A character variable used to retrieve invalid input from the buffer
*   @currentInput - A float variable to store the current input value from the user
*   @message - A constant character string stores a custom prompt message
*
*   Loop condition:
*        @count < @limit
*
*   Execution step
*       - Prompt to the user to enter a set of real numbers
*       - Read user input and store the result in @status
*
*   Condition handling:
*       - If @status == 1:
*           - Display an accepted message.
*           - Display the number entered.
*           - Increment @count.
*           - Display the custom prompt message.
*
*       - If @status != 1:
*           - Display a rejected input message.
*           - Display the custom prompt message.
*
*   Condition handling
*       - If @count == @limit:
*           - Display  a message indicating that all elements were filled
*
*
* ========================================
* Module Dependency
* ========================================
* NONE
*
* ========================================
* Library Dependency
* ========================================
* stdio.h - standard input / output
* ctype.h  - standard character
*/
int get_set_of_numbers(float numbers[], const int limit){
    int count = 0, status = 0;
    char c;
    float currentInput;
    const char *message = "Enter another numbers %d of %d or type 'q' to quit\n";
    printf("Enter a set of real numbers until %d elements or type 'q' to quit\n", limit);
    do{
        status = scanf("%f", &currentInput);
        if(status == 1){
            numbers[count] = currentInput;
            printf("the input %.2f is accepted\n", numbers[count]);
            if(count < limit)
                printf(message, count + 1, limit);
            count++;
        }else{
            scanf(" %c", &c);
            printf("The input '%c' is rejected\n", c);
            printf(message, count + 1, limit);
            if(tolower(c) == 'q'){
                puts("Quiting the program");
                break;
            }
        }
        while((c = getchar()) != '\n' && c != EOF);
    }while(count < limit);
    
    if(count == limit)
        printf("All elements in %d the array was filled\n", count);

    return count;
}