# System `get_set_of_number()`

## Purpose
Collect a set of real numbers

## Scope
* It will:
    - Prompt for a set of real numbers
    - Stop when it reaches 10 elements
    - Return the number of inputs entered
* It will not:
    - Handle invalid character
    - Store numbers in external storage

## Algorithm
1. Prompt for a real number
2. Store the input
3. Increment the counter
4. Repeat until the maximum number of element is reached

## Data Structure
`Real numbers array` - Store set of real numbers as a reference array
`Constant Integer limit variable`  - Set the limit of input as a constant
`Integer count variable`  - Count the elements entered by the user as local variable

## Pseudocode
~~~
Function Integer get_set_of_numbers(Real Ref numbers[], Constant Integer limit)
    Declare Integer count = 0 number

    For count = 0 To limit - 1
        Display "Enter a numbers left", limit - count
        Input numbers[count] 

        Set count = count + 1 
    End for 

    Return count
End function
~~~
~~~c
int get_set_of_numbers(float numbers[], const int limit){
    int count = 0;

    for(count = 0; count < limit; count++){
        printf("Enter numbers left: %d\n", limit - count);
        scanf("%f", &numbers[count]);
    }

    return count;
}
~~~

| Module details       | Field                                 |
|----------------------|---------------------------------------|
| **Name**             | `get_set_of_numbers`                  |
| **Number of inputs** | 2 (array reference, maximum number)   |
| **Process**          | Prompt for a set of real numbers      |
| **Output**           | Real numbers stored in provided array |
| **Return**           | Number of inputs entered              |