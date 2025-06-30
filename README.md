*Company* : CodeTech IT Solutions
*Name* : Yash Raj
*Intern ID* : CT04DG560
*Domain* : C Programming
*Duration* : 4 Weeks
*Mentor* : Neela Santhosh

## Table of Contents
- [✅ Task 1: File Handling]
- [✅ Task 2: Singly Linked List]
- [✅ Task 3: Lexical Analyzer in C]

### Task 1: File Handling in C
**Description:**
A basic C program that performs the following file operations:
- Creates a new file
- Writes user input to the file
- Appends additional content
- Reads and displays file content

**File Name:** `task_1.c`  
**Output File:** `codtech.txt`

**How to Run (in terminal):**
bash
gcc task_1.c -o task_1
./task_1

---
### Task 2: Singly Linked List in C
**Description:**  
This C program implements a basic singly linked list with:
- Insertion at the end
- Deletion by value
- Displaying the full list

**File Name:** `task_2.c`

#### Sample Test Input:
1 → 10  
1 → 20  
1 → 30  
3 →  Display  
2 → 20 (delete)  
3 →  Display

**How to Run (in terminal):**
bash
gcc task_2.c -o task_2
./task_2


---
### ✅ Task 3: Lexical Analyzer in C

**Description:**  
This C program performs a basic lexical analysis on a given `input.c` file. It:
- Identifies **keywords** (e.g., `int`, `float`, `return`)
- Identifies **operators** (e.g., `=`, `+`)
- Treats all other valid tokens as **identifiers** (e.g., `main`, `x`, `y`, `5`, `2`, etc.)


** Files:**
- `task_3.c` → Lexical analyzer source code
- `input.c` → Sample input C code for analysis


###  Sample `input.c` (used for testing):

```c
int main() {
    int x = 5;
    float y = x + 2;
    return 0;
}
