# System - [sort_real_numbers]

## Purpose
Reorder real numbers in ascending order

## Scope
* It will:
    - Reorder the input set of real number

* It will not:
    - Validate empty input
    - Prompt for inputs to the user
    - Display inputs
    - Store input in extenal storage
    - Return any value

## Algorithm
1. Iterate through the set of real numbers
2. Compare adjacent values
3. Reorder values when required
4. Repeat until the set is sorted

## Data Structure
`Real numbers` - Contain the inputs to be sort as a reference array
`Constant Integer limit` Maximum number of elements in `numbers` 

## Pseudocode
~~~
Module sort_real_numbers(Real Ref numbers[], Contant Integer limit)
    Declare i, j, current, next
    For i = 0 To limit - 1
        For j = 0 To limit - (i + 1)
            Set current = j
            Set next = j + 1

            If numbers[current] > numbers[next] Then
                Call swap(numbers[current], numbers[next])
            End if
        End for
    End for
End module


Module swap(Real Ref a, Real Ref b)
    Declare Real temp
    temp = a
    a = b
    b = temp
End module
~~~

## Implementation
~~~c
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
~~~

| Module details       | Field                                           |
|----------------------|-------------------------------------------------|
| **Name**             | `sort_real_numbers`                             |
| **Number of inputs** | 2 (array reference, maximum number)             |
| **Process**          | Reorder a set of real numbers in asceding order |
| **Output**           | Sorted numbers are stored in provide array      |
| **Return**           | None                                            |
