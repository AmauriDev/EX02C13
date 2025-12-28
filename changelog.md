# CHANGELOG

All notable change of [02-exercise] will be documented in this file.

## Unreleased

### Planned

## [1.0.0] 2025-12-28
- `get_set_of_real_numbers` - Collect a set of real numbers.
- `sort_rea_numbers`        - Sort a set of real numbers in ascending order.
- `display_numbers`         - Display a set of real numbers.

## [0.3.0] 2025-12-22
### Added
`sort_real_numbers`

**Purpose:**
Sort a set of real numbers in ascending order

**Inputs:**
- `numbers` - A float array
- `limit`   - Maximum number of elements in `numbers`

**Process:**
- Declare the following variables:
  - `i` - An integer variable for outer loop.
  - `j` - An integer variable for inner loop.
  - `next` - An integer semantic variable to represent next value
  - `current` An integer semantic variable to represente current value

- For each `i` to `limit` - 1
  - For each `j` to `limit`
    1. Set `current` = `j`
    2. Set `next` = `current` + `1`
    3. If `current` > `next`, swap current and next

**Output:**
- The sorted result are store in provided array.
- Return: None

**Dependencies**
This module requires a private local module calls `swap`

## [0.2.0] 2025-12-20
### Added
- `display_numbers`

**Purpose:**
Display a set of real numbers

**Inputs:**
- `numbers` - A constant float array that contains inputs values
- `limit`   - A constant integer set the maximum nomber of elements in `numbers`

**Process:**
- Declare the following variable:
  - `index` An integer variable, it stores increment value for count-controlled loop.

- Condition loop.
  - `index` < `limit`:

- Execution step:
    1. For each elements:
       1. Print its value to the user
       2. Evaluate if `index` % `10` == `9`, true print a newline

    - Condition `index` % `10` != `0`
        1. Print a newline

**Output:**
    - Each element in `numbers` is printed
    - None: return value

## [0.1.0] 2025-12-17
### Added
- `get_set_of_real_numbers`

**Purpose:**
Collect a set of real numbers

**Inputs:**
- `numbers` - A float array to store each input provided by the user
- `limit`   - A constant integer set the maximum number of elements in `numbers`

**Process:**
- Declare the following variables:
  - `count` - An integer variable that stores the total number of accepted inputs and control the loop condition.
  - `status` - An integer variable that stores the result returned by `scanf()` function
  - `c`      - A character variable used to retrieved invalid input from the buffer
  - `message` - A constant character string stores a custom prompt message.

- Loop condition. `count` < `limit`:
  - Execution step:
    1. Prompt to the user to enter a set of real numbers.
    2. Read user input and store the result in `status`

  - Condition handling:
    - If `status` == 1:
        1. Display an accepted message.
        2. Display the number entered
        3. Increment `count`
        4. Display the custon prompt message
    - If `status` != 1
      1. Display a rejected input message.
      2. Display the custom prompt message.

- Condition handling
  - If `count` == `limit`:
    1. Display a message indicating that all elements were filled

- Return `count`