# System `display_numbers()`

## Purpos
Display a set of real numbers.

## Scope
* It will:
    - Print a set of real numbers

* It will not:
    - Validate empty inputs
    - Store input in external source
    - Alter inputs
    - Return any value

## Algorithm
1. Iterate in a loop
   1. Declare an index variable
   2. evaluate if index is less than limit
   3. Print each input from index to limit

## Data Structure
`Constant Real numbers array` - Contain the input numbers to be display
`Constant Integer limit` - Maximum number of elementsin `numbers`

## Pseudocode

~~~
Module display_numbers(Constant Real numbers[], Constant Integer limit)
    For Declare Integer index = 0 To limit - 1
        Display numbers[index]
        Set index = index + 1
    End for
End module
~~~

~~~c
#include <stdio.h>
void display_numbers(const float numbers[], const int limit){
    for(int index = 0; index < limit; index++)
        printf("%.2f\n",  numbers[index]);
}
~~~

**Dependency**
Standard input / output `stdio.h`

| Module details       | Field                                        |
|----------------------|----------------------------------------------|
| **Name**             | `display_numbers`                            |
| **Number of inputs** | 2 (Constant float array, Constant int limit) |
| **Process**          | Iterate through each element to be display it|
| **Output**           | Displayed real numbers                       |
| **Return**           | None                                         |