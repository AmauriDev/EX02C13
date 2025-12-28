# Module Specification Document

## 1. Define Objective
### 1.1 Problem analysis
*The Sorting Real Numbers* system needs to collect a set of real numbers from user

**Information extracted from SRS**
Data type: Real
Numbers of elements: 100
User can stop the collecting process typing the `q` character

- **ID:**   `FR-1`
- **Name:** `get_set_of_real_numbers`
- **Purpose:** Collects a set of real numbers from the user, until either 100 elements are reached or the input process is terminated
- **Dependency:** NONE
- **Category:** Input

### 1.2 Requirements
User inputs

### 1.3 Purpose
Collect a set of real numbers

### 1.4 Scope
* It will:
    - Prompt for a set of real numbers
    - Display whether the input is accepted or rejected
    - Stop when it reaches the limit of elements
    - Handle invalid input
    - The user can stop the input process by typing `q` character
    - Return the number of valid input entered
* It will not:
    - Open an external file or connect to a database
    - Store numbers in external storage
    - Extended the limit assigned by the system


### 1.5 Overall Objective
The *get_set_of_real_numbers* is a sub system of *The Sorting Real Numbers* system.
Its role is to collect valid inputs from the user.

## 2. Design
### 2.1 System Role and Boundaries
The *get_set_of_real_numbers* sub system is responsible to collect only valid real numbers input up to numbers elements defined by the *Sorting Real Numbers* system

### 2.2 Interaction with other modules
The Sorting Real Numbers systems call:
1. `get_set_of_real_numbers` - to collect inputs user if it returns valid inputs:
   1. `display_numbers` displays input entered
   2. `sort_real_numbers` reorder input values.
   3. `display_numbers` displaye sorted result.

Other modules depend on of `FR-1` collects valid input.

### 2.3 Dependencies
**Module dependencies**
None

**Library depencencies**
`stdio.h` - standard input/output

### 2.4 Overall Design
The `get_set_of_real_numbers` is an input interfaces between user and the main functionality in *Sort Real Numbers* system

## 3. Implementation
### 3.1 Technology Decision
This exercise belongs to a set of C programming exercises from `C primer plus` for this reason, the  `C language` was selected as the implementation technology

### 3.2 Algorithm
1. Prompt for a real number
2. Store the input
3. Increment the counter
4. Repeat until the maximum number of element is reached

### 3.3 Data Structure
`Real numbers array` - Store set of real numbers as a reference array
`Constant Integer limit variable`  - Set the limit of input as a constant
`Integer count variable`  - Count the elements entered by the user as local variable

### 3.4 Pseudocode
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

### 3.5 Code
~~~c
int get_set_of_numbers(float numbers[], const int limit){
    int count = 0, status = 0;
    char c;
    const char *message = "Enter another numbers %d of %d or type 'q' to quit\n";
    printf("Enter a set of real numbers until %d elements or type 'q' to quit\n", limit);
    do{
        status = scanf("%f", &numbers[count]);
        if(status == 1){
            printf("the input %.2f is accepted\n", numbers[count]);
            if(count < limit)
                printf(message, count + 1, limit);
            count++;
        }else{
            scanf(" %c", &c);
            printf("The input '%c' is rejected\n", c);
            printf(message, count + 1, limit);
            if(tolower(c) == 'q'){
                break;
            }
        }
        while((c = getchar()) != '\n' && c != EOF);
    }while(count < limit);
    
    if(count == limit)
        printf("All elements in %d the array was filled\n", count);
    else if(count == 0)
        puts("Quiting the program");

    return count;
}
~~~

## 4. Testing
### 4.1 Test plan
**Objective**
Verify that the *get_set_of_real_numbers* subsystem works correctly, ensuring that the execution flow, the stored inputs, and return values match the expected behavior.

**What will be tested**
1. The subsystem collects a set of real numbers.
2. The subsystem displays a clear prompt
3. The subsytem acceptes only valid inputs
4. The subsystem rejectes invalid inputs
5. Return the numbers of valid inputs entered


**Acceptance criteria**
1. Input collection
   - Until it filled or user stops the processs.
2. Input validation
   - Accept only valid real numbers.
   - Reject invalid inputs.
3. Return value
   - Return the total number of valid inputs entered

### 4.2 Test Procedure
| Test Case | Description                          |
|-----------|--------------------------------------|
| `TC-1`    | Don't collect inputs                 |
| `TC-2`    | Valid input input up to 10 elements  |
| `TC-3`    | Mix inputs, valid, and invalid       |
| `TC-4`    | All invalid inputs up to 10 elements |

#### ID [TC-1]
**Input:** `q`

**Step:**
1. Run the subsystem (Independently)
2. Input: `q`
3. Process: Stop collecting input
4. return `0`
5. End the subsystem

**Expected behavior:**
- Value stored: `No values stored in the numbers array`
- Return: `0`

#### ID [TC-2]
**Input:** `10, 3.2, 5.5, 5, 9.9, 9.90, 9.92, 10.01, 2.2, 9, q`

**Step:**
1. Run the subsystem (Independently)
2. Enter the provided inputs
3. Enter `q` to stop the input process
4. End the subsystem

**Expected behavior:**
- Accepted inputs: All valid real numbers entered except
- Rejected inputs: None.
- Value stored: `10, 3.2, 5.5, 5, 9.9, 9.90, 9.92, 10.01, 2.2, 9`
- Return `10`
- Input termination triggered by user command (`q`)

#### ID [TC-3]
**Inputs:** `a, 4, c, 5, q`

**Step**
1. Run the subsystem (Independently)
2. Enter the provided inputs.
3. Enter `q` to stop the input process
4. End the subsystem

**Expected behavior:**
- Accepted inputs: `4`, `5`
- Rejected inputs: `a`, `c`  
- Value stored: `4`, `5`
- Return: `2`
- Input termination triggered by user command (`q`)

#### ID [TC-4]
**Inputs:** `a, b, c, d, e, f, g, j, o, p, q`

**Step:**
1. Run the subsystem independently
2. Enter the provided inputs
3. Enter `q` to stop the input process
4. End the subsystem

**Expected behavior:**
- Rejected inputs: `a`, `b`, `c`, `d`, `e`, `f`, `g`, `j`, `o`, `p`
- Value stored: `None`
- Return: `0`
- Input termination triggered by user command (`q`), not by reaching the input limit.

### 4.3 Test result
| Test case | Input values                                         | Accepted result                                   | Return value  | Pass/Fail |
|-----------|------------------------------------------------------|---------------------------------------------------|---------------|-----------|
| `TC-1`    | `q`                                                  | `No values accepted`                              | `0`           | `Pass`   |
| `TC-2`    | `10, 3.2, 5.5, 5, 9.9, 9.90, 9.92, 10.01, 2.2, 9, q` | `10, 3.2, 5.5, 5, 9.9, 9.90, 9.92, 10.01, 2.2, 9` | `10`          | `Pass`   |
| `TC-3`    | `a, 4, c, 5, q`                                      | `4, 5`                                            | `2`           | `Pass`   |
| `TC-4`    | `a, b, c, d, e, f, g, j, o, p, q`                    | `No values accepted`                              | `0`           | `Pass`   |

### 4.4 Test Summary
The *get_set_of_real_numbers* subsystem successfully completed all previously defined test cases.
The result confirm that the subsytem behaves as expected by:

- Terminating input process immediately when the user requests it.
- Collecting up to maximum number of valid real numbers inputs.
- Correctly handling mixed inputs by accepting valid values and rejecting invalid ones.
- Reject all invalid inputs when no valid data is provided

## 5. Maintenance
### 5.1 Current LimitationS
- The input terminator character is defined by the design process.
 
### 5.2 Future Improvements
- The input character terminator could be change 

| Module details       | Field                                 |
|----------------------|---------------------------------------|
| **Name**             | `get_set_of_numbers`                  |
| **Number of inputs** | 2 (array reference, maximum number)   |
| **Process**          | Prompt for a set of real numbers      |
| **Output**           | Real numbers stored in provided array |
| **Return**           | Number of inputs entered              |