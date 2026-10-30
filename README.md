# Calculator-in-C
# SciCalc - Scientific Calculator in C

SciCalc is a command-line scientific calculator written in C. I built this project to practise the fundamentals of C programming and apply them to something more practical than individual practice programs.

It started with basic arithmetic operations and gradually grew to include powers, roots, logarithms, trigonometric functions, and other mathematical operations. I also added a feature that allows the calculator to reuse the previous result, so you can perform multiple calculations without entering the same values repeatedly.

The project is still open to improvements, but the main goal was to build something functional while getting more comfortable with functions, pointers, input handling, conditional statements, and the C math library.

## Features

### 1. Basic Arithmetic
- Addition
- Subtraction
- Multiplication
- Division
- Modulus using `fmod()`

### 2. Powers and Roots
- Raising a number to a given power
- Square root
- Cube root

### 3. Other Mathematical Operations
- Absolute value
- Natural logarithm
- Base-10 logarithm
- Base-2 logarithm
- Exponential function (\(e^x\))
- Hypotenuse calculation using two values

### 4. Trigonometric Functions
- Sine
- Cosine
- Tangent
- Inverse sine
- Inverse cosine
- Inverse tangent

### 5. Previous Answer Reuse

SciCalc can store the result of a successful calculation and offer it as an input for the next operation. For operations that require two numbers, the previous answer can be used as the first number while the second number is entered separately.

This makes consecutive calculations easier and also gave me a reason to work with pointers and pass values between functions.

### 6. Input and Error Handling

The calculator includes basic checks for invalid input and mathematical errors. These include:

- Division by zero
- Modulus by zero
- Square roots of negative numbers
- Logarithms of zero or negative numbers
- Inverse sine and cosine inputs outside their valid range
- Non-finite results from operations such as exponentiation

Invalid menu choices and certain incorrect inputs are also handled without immediately terminating the program.

## Technologies Used

- C - Main programming language
- Standard C Library - Input/output and program utilities
- Math Library (`math.h`) - Mathematical functions such as `sqrt()`, `pow()`, `sin()`, `log()`, `fmod()`, and `hypot()`
- Git and GitHub - Version control and project hosting

## Getting Started

### Prerequisites

You need a C compiler such as GCC and a terminal to compile and run the program.

If you are using Git Bash on Windows, make sure GCC is installed and available in your system's PATH. Git Bash itself is a terminal environment and does not automatically include a C compiler.

### Clone the Repository

git clone <YOUR_REPOSITORY_URL>
cd <YOUR_REPOSITORY_FOLDER>

Replace the placeholders with your actual GitHub repository URL and folder name.

### Compile the Program

If your source file is named `scical.c`, compile it using:

gcc scical.c -o scical -lm

The `-lm` flag links the math library on systems where it is required.

### Run the Calculator

On Linux or macOS:

./scical

On Windows using Git Bash:

./scical.exe

Depending on your compiler setup, you may also be able to run the generated executable directly from your terminal.

## How to Use

1. Run the compiled program.
2. Choose an operation from the numbered menu.
3. Enter the required number or numbers when prompted.
4. For supported operations, choose whether to reuse the previous answer.
5. Continue calculating or select option `21` to exit.

For example, you could add `12` and `8` to get `20`, then choose multiplication and reuse `20` as the first input.

Note: Trigonometric functions use radians, not degrees.

## What I Learned

Building SciCalc has helped me practise several concepts that are important in C:

- Breaking a program into smaller functions instead of putting everything inside `main()`.
- Passing arguments to functions and returning calculated values.
- Using pointers to let helper functions update variables declared in `main()`.
- Working with `scanf()` and handling some invalid input cases.
- Using `NAN`, `isnan()`, and `isfinite()` to detect mathematical errors and invalid results.
- Using functions from the C math library.
- Managing source code with Git and maintaining a project on GitHub.

The previous-answer feature was particularly useful because it required me to think about how data should move between different functions and how the calculator should behave when a calculation fails.

## Current Limitations

SciCalc is a terminal-based project, so it does not have a graphical interface. Its input validation also has some limitations, particularly when handling partially valid numeric input or unusual floating-point values.

The program is a learning project, and there is room to improve the consistency of error handling and make the input system more robust.

## Future Improvements

Some improvements I would like to explore include:

- More consistent error handling across all operations
- Better validation of numeric input
- An option to use degrees instead of radians for trigonometric calculations
- A calculation history feature
- A cleaner, more organised menu
- More extensive testing of edge cases

## Author

Amitabh Chatterjee
ECE Freshman, Heritage Institute of Technology, Kolkata

Feedback, suggestions, and constructive criticism are welcome.

---

SciCalc is a learning project intended for practice and experimentation.
