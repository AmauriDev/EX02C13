# Module Specification Document

## 1. Define Objective
### 1.1 Problem Analysis
The *Sortin Real Numbers* system requires a functionality that reorder a set of real numbers in ascending order is the main funcitonality 

### 1.2 Requirements
A set of real numbers

**Information extracted from SRS**
---

- **ID:** `FR-2`    
- **Name:** `sort_real_numbers`
- **Purpose:** Reorder a set of real numbers in ascending order
- **Dependency:** `FR-1`
- **Category:** Process

---

### 1.3 Scope
* It will:
    - Reorder the input set of real number

* It will not:
    - Validate empty input.           *Sorting Real Numbers* system is responsible to evaluate inputs
    - Prompt for inputs to the user.  `FR-1` is responsible to collect them
    - Display inputs.                 `FR-3` is responsible to display them
    - Store input in extenal storage. System constraints
    - Reorder in descending order.    System constraints
    - Return any value.               Module constraints

### 1.4 Purpose
Reorder real numbers in ascending order

### 1.5 Overall Objective
The *sort_real_numbers* is a subsystem of *Sorting Real Numbers* system.
Its role is to reorder real numbers

## 2. Design
### 2.1 System role and Boundaries
The *sort_real_numbers* subsystem is responsible to sort real numbers in ascending order.
The inputs and limit of elements are provided by the *Sorting Real Numbers* system.

### 2.2 Interaction with other Modules
The *Sorting Real Numbers* system provided real numbers inputs.
The *sort_real_numbers* subsystem evaluates whether inputs need to be swap of places, and call *swap* local subsystem to perfom this action

### 2.3 Dependencies

**Module dependencies**
`swap` private local module

**Library dependencies**
`NONE`

### 2.4 Overall Design
The *sort_real_numbers* subsystem is the core functionality of the *Sorting Real Numbers* system 

## 3. Code
### 3.1 Technology Decision

### 3.2 Algoritm
1. Iterate through the set of real numbers
2. Compare adjacent values
3. Reorder values when required
4. Repeat until the set is sorted

### 3.3 Data Structure
`Real numbers` - Contain the inputs to be sort as a reference array
`Constant Integer limit` Maximum number of elements in `numbers` 

### 3.4 Pseudocode
~~~
Module sort_real_numbers(Real Ref numbers[], Contant Integer limit)
    Declare i, j, current, next
    For i = 0 To limit - 1
        For j = 0 To limit - (i + 1)
            Set current = j
            Set next = current + 1

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

### 3.5 Code
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

static void swap(float *a, float *b){
    float temp = 0.0;
    temp = *a;
    *a = *b;
    *b = temp;
}
~~~

## 4. Testing
### 4.1 Test Plan
- **Objective:**
Verify that the *sort_real_numbers* subsystem works correctly reorder real numbers

**What will be tested:**
- The subsystem reorder real numbers

**Accepteace Criteria:**
- Each real numbers is roerder from smaller to larger until the set of sorted in ascending order

### 4.2 Test Procedure
| Test Case | Description                                              |
|-----------|----------------------------------------------------------|
| `TC-1`    | Positive real numbers up to 10 elements                  |
| `TC-2`    | Negative real numbers up to 10 elements                  |
| `TC-3`    | Mix positive and negative real numbers up to 10 elements |

**Note** *display_numbers* is used only to visualize the sorted output; its is not part of the sorting logic being tested

- ID [TC-1]
**Inputs:** `1.9, 1.8, 1.7, 1.6, 1.5, 1.4, 1.3, 1.2, 1.1, 1.0`

**Step:**
1. Run the subsystem independently
2. Process the provided inputs
3. Display sorted result
4. End the subsystem

**Expectected behavior:**
- Sorted result
`1.00 1.10 1.20 1.30 1.40 1.50 1.60 1.70 1.80 1.90`

- ID [TC-2]
**Inputs:** `-5, -3, -4, -1, -2, -8, -9, -6, -7, -10`

**Step:**
1. Run the subsystem
2. Process the provided inputs
3. Display sorted result
4. End the subsystem

**Expected behavior:**
- Sorted result
`-10.00 -9.00 -8.00 -7.00 -6.00 -5.00 -4.00 -3.00 -2.00 -1.00`

- ID [TC-3]
**Inputs;** `-5, -3, -4, -1, -2, 1.9, 1.8, 1.7,  1.6, 1.5`

**Step:**
1. Run the subsystem
2. Process the provided inputs
3. Display sorted result
4. End the subsystem

**Expected behavior:**
- Sorted result
`-5.00 -4.00 -3.00 -2.00 -1.00 1.50 1.60 1.70 1.80 1.90`

### 4.3 Test Result
| Test Case | Inputs                                             | Output                                                         | Pass/Fails |
|-----------|----------------------------------------------------|----------------------------------------------------------------|------------|
| `TC-1`    | `1.9, 1.8, 1.7, 1.6, 1.5, 1.4, 1.3, 1.2, 1.1, 1.0` | `10.00 9.00 8.00 7.00 6.00 5.00 4.00 3.00 2.00 1.00`           | `Pass`     |
| `TC-2`    | `-5, -3, -4, -1, -2, -8, -9, -6, -7, -10`          | `-10.00 -9.00 -8.00 -7.00 -6.00 -5.00 -4.00 -3.00 -2.00 -1.00` | `Pass`     |
| `TC-3`    | `-5, -3, -4, -1, -2, 1.9, 1.8, 1.7,  1.6, 1.5`     | `-5.00 -4.00 -3.00 -2.00 -1.00 1.50 1.60 1.70 1.80 1.90`       | `Pass`     |

### 4.4 Test Summary
The *sort_real_numbers* subsystem completed successfully all the previously defined test.
Those results confirm that the subsystem behaves as expected

## 5. Maintenance
### 5.1 Current Limitation
- The subsystem only reorder real numbers in ascending order
- The subsystem supports the Bubble Sort algorithm only
- The subsystem is limited to single-precision floating-point representation (`float`), providing approximately 6–7 significant decimal digits of precision.

### 5.2 Future Improvements
- Support descending order sorting.
- Support alternative sorting algorithms (e.g., more efficient algorithms for large datasets).
- Support double-precision floating-point representation to increase numeric precision.


| Module details       | Field                                           |
|----------------------|-------------------------------------------------|
| **Name**             | `sort_real_numbers`                             |
| **Number of inputs** | 2 (array reference, maximum number)             |
| **Process**          | Reorder a set of real numbers in asceding order |
| **Output**           | Sorted numbers are stored in provide array      |
| **Return**           | None                                            |
