# Software Requierements Document

## Project Details
- **Project Name:** `Sorting Real Numbers`
- **Project Version:** `1.0.0` Release
- **Project Status:** `Finalized`
- **Start Date:** `2025-12-15`
- **End Date:** `2025-12-27
---
- **Client Name:** `Estephany Villa Corniel`
- **Client Validation:** `Approved`
---

## 1. Objective definition
### 1.1 Problem Analysis
Estephany, who works as an accountant need to sort numbers system, she needs that it let her to enter a list of numbers and sort them, then display them in increasing order

**Some answers questions:**

- What type of numbers?
Real numbers.

- How many numbers do you think to enter?
Between 1 to 100

- Exactly 100 numbers?
No, it can be untill 100 numbers but she wants to stop if she needed 

- Would you like to see numbers before and after sort operation?
Yes.

- Do the data need to be storage in file or database?
For now, she didn't want to save the result but maybe in the future.

**Answer summary**
- The system will accept real numbers entered by the user.
- The user can enter between 1 and 100 numbers and may stop the input process at any time.
- The system will sort real number in ascending order
- The system will display the numbers before and after sorting.
- The data will no be stored in external storages

### 1.2 Requirements
The system must meet the following functional requirements

### 1.2.1 Functional Requirements

- **ID:**   `FR-1`
- **Name:** `get_set_of_numbers`
- **Purpose:** Collects a set of real numbers from the user, until either 100 elements are reached or the input process is terminated
- **Dependency:** NONE
- **Category:** Input

---

- **ID:** `FR-2`    
- **Name:** `sort_real_numbers`
- **Purpose:** Reorder a set of real numbers in ascending order
- **Dependency:** `FR-1`
- **Category:** Process

---

- **ID:** `FR-3`
- **Name:** `display_numbers`
- **Purpuse:** Display a set of numbers to the user, before or after they are sorted.
- **Dependency:** `FR-1`
- **Category:** Output

### 1.2.2 Non-Functinal Requierements
| **ID**  | **Description**                                                                                | Category                       |
|---------|------------------------------------------------------------------------------------------------|--------------------------------|
| `NFR-1` | The system must run in console.                                                                | Interface                      |
| `NFR-2` | The system must accept user input via keyboard.                                                | Input                          |
| `NFR-3` | The system must provide a responsive mechanist to terminate input before reaching all elements | Usability                      |
| `NFR-4` | The system must operate entirely in volatile memory, without using external storage            | Resource                       |
| `NFR-5` | The system must display outputs in clear and readable format for the user.                     | Usability                      |


### 1.2.3 Constraints
- The system does not accept command-line parameters
- The system does not read input from external sources such as a files or databases
- The system does not store data in files or databases
- Input collection terminate early when the user enters a designated terminator character ('#'), subject to change
- The system performs only one sorting operation per execution. To perform another sort operation, the system must be restarted
- The system does not reorder in descending order

### 1.3 Purpose
The system allows the user to enter real numbers, sort them and then display the sorted result

### 1.4 Scope
**The system will:**
- Prompt the user to enter a set of real numbers.
- Sort the real numbers in increasing order.
- Display both the entered numbers and the sorted results.

**The system will not:**
- Read data from files for sorting.
- Storage any data in external files or databases
- Allow restarting the proess to perform a new sorting task.

### 1.5 Overall Objective
Process a set of real numbers and produce an increasing ordered result.

### 1.6 MVP Objectives

The Minimum Viable Product must be able to:

1. Receive a set of real numbers from the user
2. Process and reorder the values according to the defined sorting criteria
3. Produce the ordered result to be display to the user

## 2. Design
### 2.1 System role and boundaries
| Component | Implement |
|-----------|-----------|
| Input     | FR-1      |
| Process   | FR-2      |
| Output    | FR-3      |

The system is organized into three main components:
1. An input component responsible for collecting numeric values `get_set_of_numbers`
2. A processing component that applies the sorting logic.   `sort_real_numbers`
3. A presentation component that renders the ordered result to the user.    `display_numbers`

Each component operates independently and communicates through well-defined data boundaries.

### 2.2 Interacton with other modules
The `FR-1` provides a collection of numeric values to the processing component.
The `FR-2` applies the sorting logic and forwards the ordered result to the presentation component
The `FR-3` receives the processed data and renders the ordered result to the user.

### 2.3 Dependencies
The system depends only on standard input and output mechanisms provided by the execution environment.

### 2.4 Overall Design
The system is designed as a simple layered structure composed of an input component, a processing component, and a presentation component.
This separation of responsibilities ensures that the core processing logic remains independent from input and presentation mechanisms.

## 3. Implementation
### 3.1 Technology decision 
This exercise belongs to a set of C programming exercises from `C primer plus` for this reason, the  `C language` was selected as the implementation technology

### 3.2 Algorithm
1. Get set of real numbers `FR-1`
2. Display inputs entered `FR-3`
3. Sort in asceding order `FR-2`
4. Display sorted inputs `FR-3

### 3.3 Code
~~~c
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
~~~

## 4. Testing
### 4.1 Test Plan
**Objective**
Verify that the *Sorting Real Numbers* system works correctly, ensuring that the execution flow and the observed behavior match the expected behavior.

**What will be tested:**
1. The system collects a set of real numbers.
2. The system displays all inputs entered by the user.
3. The system sorts in ascending order.
4. The system displays sorted result

**Acceptance criteria**
1. Input collection
  - Until it is filled or user stops the process.
2. Process sorting
  - Reorder in ascending order.
3. Output to the user
  - Display real numbers with two decimal places.
  - Display up to 10 values per line.

### 4.2 Test Procedure
#### Test case 1 - Don't collect input
**Input:** `q`

**Step:**
1. Run the program
2. Input: `q`
3. `FR-1` is responsible to collect input
4. Return count : `0` `count == 0`
5. Process: Stop collecting real numbers
6. Output: No data entered
7. End the program

**Expected behavior:**
- Value stored : `No values stored in the numbers array`
- Return count : `0`
- Sorting process is not executed
- Program display:  `No data entered`

#### Test case 2 - Collect up to 10 valid input
**Inputs:** `10, 3.2, 5.5, 5, 9.9, 9.90, 9.92, 10.01, 2.2, 9, q`

**Step:**
1. Run the program
2. Input: Set of numbers up to 10 valid elements
3. `FR-1` is responsible to collect inputs
4. Return count : `10` `count` > 0
5. `FR-3` display original input entered
6. `FR-2` Executed reorder process in ascending order
7. `FR-3` Display sorted input
8. End the program

**Expected behavior:**
- Value stored: `10, 3.2, 5.5, 5, 9.9, 9.90, 9.92, 10.01, 2.2, 9`
- Return count : `10`
- Sorting process: Executed in ascending order
- Program display : `2.20, 3.20, 5.00, 5.50, 9.00, 9.90, 9.90, 9.92, 10.00, 10.01`

#### Test case 3 - Mix inputs 2 valid inputs and 2 invalid inputs
**Inputs:** `a, 4, c, 5, q`

**Step**
1. Run the program
2. Input: Mix values up to 4 elements
3. `FR-1` is responsible to collect inputs
   1. Invalid inputs are rejected and prompt again.
   2. Valid inputs are store and continue collects
   3. Return valid inputs entered
4. Return count : `2` `count` > 0
5. `FR-3` display original inputs entered
6. `FR-2` Exercuted reorder process in ascending order
7. `FR-3` display sorted input
8. End the program

**Expected behavior**
- Value stored: `4, 5`
- Value rejected `a, c`
- Return count : `2`
- Sorting process: Executed in ascending order
- Program display : `4.00, 5.00`

#### Test case 4 - Invalid inputs 5 elements
**Inputs:** `a, b, c, d, e, q`

**Step**
1. Run the program
2. Input: Invalid values
3. `FR-1` is responsible to collect inputs.
   1. Invalid inputs are reject and prompt again
   2. No valid inputs are stored.
4. Return count : `0` `count == 0`
5. `FR-2` and `FR-3` are not executed
6. Program ends displaying: `No data entered`

**Expected behavior:**
- Value stored: `NONE`
- Value rejected: `a, b, c, d, e`
- Return count : `0`
- Sorting process: is not executed
- Program displays: `No data entered`


### 4.3 Test Result
You will fill this manually after running the system

| Test Case | Data input                                           | Data output                                                    | Expected result   | Pass/Fail|
|-----------|------------------------------------------------------|----------------------------------------------------------------|-------------------|----------|
| 1         | `q`                                                  | `No data entered`                                              | `No data entered` | `Pass`   |
| 2         | `10, 3.2, 5.5, 5, 9.9, 9.90, 9.92, 10.01, 2.2, 9, q` | `2.20, 3.20, 5.00, 5.50, 9.00, 9.90, 9.90, 9.92, 10.00, 10.01` | `Sorting result`  | `Pass`   |
| 3         | `a, 4, c, 5, q`                                      | `4, 5`                                                         | `Sorting result`  | `Pass`   |
| 4         | `a, b, c, d, e, q`                                   | `No data entered`                                              | `No data entered` | `Pass`   |

### 4.4 Test Summary
The *Sorting Real Numbers* system successfully completed the previously defined test cases:
- Collect inputs from the user.
- Display original inputs entered.
- Reorder them in ascending order.
- Display sorted result

## 5. Maintenance
### 5.1 Current limitation
- The system operates only in console application.
- The system does not read input from external storage.
- The system limits of numbers input is 100 elements
- The system only sorts in ascending order.
- The system uses bubbler sort algorithm.
- The system only displays values with two decimal places.
- The system does not store sorted result in external storage.
- The system does not perfom another sorting operation without restarting the program.

### 5.2 Future improvements
- Extend the number of  decimal places displayed.
- Support sorting in descending order.
- Allow the user to select the sorting order (ascending or descending).
- Expand test coverage to include new features and behaviors.

## 6. Revision History
| Version | Date        | Author        | Description                                                                                   |
|---------|-------------|---------------|-----------------------------------------------------------------------------------------------|
| 1.0     | 2025-12-15  | Amauris Frias | Initial implementation from scratch following based on Exercise 2, Chapter 13 (C Primer Plus) |