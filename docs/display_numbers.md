# Module Specification Document

## 1. Define Objective
### 1.1 Problem Analysis
The *Sorting Real Numbers* system needs an output interface to display inputs entered before and after the sorting process

**Information extracted from SRS**
- **ID:** `FR-3`
- **Name:** `display_numbers`
- **Purpuse:** Display a set of numbers to the user, before and after they are sorted.
- **Dependency:** `FR-1`
- **Category:** Output

### 1.2 Requirements
Real numbers inputs provided by `FR-1`

### 1.3 Scope
* It will:
    - Display a set of real numbers

* It will not:
    - Validate input values
    - Alter inputs
    - Return any value

### 1.4 Purpose
Display a set of real numbers to the user, before and after they are sorted

### 1.5 Overall Objective
The *display_numbers* is a sub system of *Sorting Real Numbers* system.
Its role is to display real numbers to the user.

## 2. Design
### 2.1 System Role and Boundaries
The *display_numbers* sub system is responsible to display all real numbers provided by the *Sorting Real Numbers* system.
It displays 10 real numbers per line with two decimal places

### 2.2 Interacion with other modules
The Sorting Real Numbers systems call:
1. `get_set_of_real_numbers` - to collect inputs user if it returns valid inputs:
   1. `display_numbers` displays input entered
   2. `sort_real_numbers` reorder input values.
   3. `display_numbers` displays sorted result.

### 2.3 Dependencies
**Module dependencies**
NONE

**Library dependencies**
`stdio.h` standard input / output

### 2.4 Overall Design
The *display_numbers* is an output interface between the user and the main functionality in *Sort Real Numbers*

## 3. Implementation
### 3.1 Technology Decision
This exercise belongs to a set of C programming exercises from `C primer plus` for this reason, the  `C language` was selected as the implementation technology

### 3.2 Algorithm
1. Iterate in a loop
   1. Declare an index variable
   2. evaluate if index is less than limit
   3. Print each input from index to limit

### 3.3 Data Structure
- `Constant Real numbers array` - Contain the input numbers to be display
- `Constant Integer limit` - Maximum number of elementsin `numbers`

### 3.4 Pseudocode
~~~
Module display_numbers(Constant Real numbers[], Constant Integer limit)
    For Declare Integer index = 0 To limit - 1
        Display numbers[index]
        If index % 10 == 9 Then
            Display
        End if
    End for

    If index % 10 != 0 Then
            Display
        End if
End module
~~~

### 3.5 Code
~~~c
void display_numbers(const float numbers[], const int limit){
    int index = 0;
    for(index = 0; index < limit; index++){
        printf("%.2f ",  numbers[index]);
        if(index % 10 == 9)
            printf("\n");
    }
    if(index % 10 != 0)
        printf("\n");

}
~~~
## 4. Testing
### 4.1 Test plan
**Objective:**
Verify that the *display_numbers* subsystem works correctly displaying real numbers to the user

**What will be tested:**
1. The subsystem displays real numbers

**Acceptance Criteria:**
- It displays with two decimal places
- It diplays 10 elements per line
- It displays a new line if there are less of 10 elements in the last line

### 4.2 Test procedure
| Test Case | Description                             |
|-----------|-----------------------------------------|
| `TC-1`    | a set of real numbers up to  5 elements |
| `TC-2`    | a set of real numbers up to 10 elements |
| `TC-3`    | a set of real numbers up to 15 elements |
| `TC-4`    | a set of real numbers up to 20 elements |

- ID [TC-1]
**Inputs:** `5, 5.5, 10, 5.6, 9.9`

**Step:**
1. Run the subsystem independently
2. Display the provided inputs
3. End the subsytem

**Expected behavior:**
- Display 
~~~
5.00 5.50 10.00 5.60 9.90`

~~~

- ID [TC-2]

**Inputs:** `5, 5.50, 10, 5.6, 9.9, 2.2, 1.1, 1.22, 8, 7` 

**Step:**
1. Run the subsystem independently
2. Display the provided inputs
3. End the subsystem

**Expected behavior:**
- Display
~~~
5.00 5.50, 10.00, 5.60, 9.90 2.20, 1.10, 1.22, 8.00, 7.00`
~~~

- ID [TC-3]

**Inputs:** `5, 5.50, 10, 5.6, 9.9, 2.2, 1.1, 1.22, 8, 7, 0.1, 0.015, 0.020, -1.0, 5.55`

**Step:**
1. Run the subsystem independently
2. Display the provided inputs
3. End the subsystem

**Expected behavior:**
- Display
~~~
5.00 5.50 10.00 5.60 9.90 2.20 1.10 1.22 8.00 7.00
0.10 0.01 0.02 -1.00 5.55

~~~

- ID [TC-4]

**Inputs:** `5, 5.50, 10, 5.6, 9.9, 2.2, 1.1, 1.22, 8, 7, 0.1, 0.015, 0.020, -1.0, 5.55, 1, 2, 3, 4, 5`

**Step:**
1. Run the subsystem independently
2. Display the provided inputs
3. End the subsystem

**Expected behavior:**
~~~
5.00 5.50 10.00 5.60 9.90 2.20 1.10 1.22 8.00 7.00
0.10 0.01 0.02 -1.00 5.55 1.00 2.00 3.00 4.00 5.00
~~~

### 4.3 Test result
Test result are displayed from capture

### 4.4 Test summary
The *display_numbers* subsystem completed successfully all previously defined test cases.
The result confirm that the subsystem bahaves as expected by:

- It displays 10 elements per line
- It displays with two decimal places
- It display a new line if there are less of 10 elements

## 5. Maintenance
### 5.1 Current Limitation
- The subsystem formats numeric output with exactly two decimal places.
- Thousands separators are not supported (e.g., `1000.00` is displayed instead of `1,000.00`)
- Output is limited to a maximum of 10 elements per line

### 5.2 Future Improvements
- Extended more decimal places
- Add support for thousands separatos in numeric output
- Support fixed-with numeric formatting using field width and space padding


| Module details       | Field                                        |
|----------------------|----------------------------------------------|
| **Name**             | `display_numbers`                            |
| **Number of inputs** | 2 (Constant float array, Constant int limit) |
| **Process**          | Iterate through each element to be display it|
| **Output**           | Displayed real numbers                       |
| **Return**           | None                                         |