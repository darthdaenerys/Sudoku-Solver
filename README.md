# **Sudoku**

Have you ever tried to solve a 9×9 Sudoku puzzle? If yes, then you must be tempted to look at the algorithm behind finding the solution.
Sudoku is a number-placement puzzle where the objective is to fill a square grid of size ’n’ with numbers between 1 to ’n’. The numbers must be placed so that each column, each row, and each of the sub-grids (if any) contains all of the numbers from 1 to ‘n’.
The most common Sudoku puzzles use a 9x9 grid. The grids are partially filled (with hints) to ensure a solution can be reached.

## **Understanding the Problem**

You are given a Sudoku puzzle and you need to fill the empty cells without violating any rules.
A sudoku solution must satisfy all of the following rules:
- There must not be any repeating character in any row
- Same goes for every column
- In addition to that, every grid is further divided into smaller grids for side square_root(N)
- Each of the smaller grids must not have repeating number.
- For every value of N, you can only insert number in the range [1, N]. Suppose that the value of N is 9, then you must insert the numbers in the range [1, 9].

## **Getting Started**
- Simply download the ```Sudoku-Solver.cpp``` file found in the ```Sudoku-Solver/``` directory. Run it using any standard C++ compiler. In case of any errors or compatibility issues, submit an issue in this git.
- Once downloaded, compiled and run, the program will print a menu and ask to enter the choice: solve,generate or quit.
- The user may enter choice as per wish and the program would run as.
- For sudoku solver choice, the user will input the values manually one-by-one seperated by whitespaces.
- Below is an example of how the input might look.

    ```
    0 2 0  6 0 8  0 0 0
    5 8 0  0 0 9  7 0 0
    0 0 0  0 4 0  0 0 0

    3 7 0  0 0 0  5 0 0
    6 0 0  0 0 0  0 0 4
    0 0 8  0 0 0  0 1 3

    0 0 0  0 2 0  0 0 0
    0 0 9  8 0 0  0 3 6
    0 0 0  3 0 6  0 9 0
    ```

- Once solved, the Sudoku puzzles shall be displayed like this.

```
    -------------------
    1 2 3  6 7 8  9 4 5
    5 8 4  2 3 9  7 6 1
    9 6 7  1 4 5  3 2 8

    3 7 2  4 6 1  5 8 9
    6 9 1  5 8 3  2 7 4
    4 5 8  7 9 2  6 1 3

    8 3 6  9 2 4  1 5 7 
    2 1 9  8 5 7  4 3 6
    7 4 5  3 1 6  8 9 2
    -------------------
```
## **How It Works**

This particular algorithm employs the use of backtracking, one of the more common methods to solve Sudoku puzzles. I've written a simple algorithm to give an idea of how the program works.

1. Start.
2. We start with the first empty cell.
3. We generate a list of possible valid values that can be filled in that cell.
4. We iterate over this list and start with the first value. This value is placed in the required cell.
5. We move on to the next cell. We again generate a list of possibilities. However, if no list can be generated, then this means that there is something wrong with the value of the previous cell. We then move back to the previous cell and place the next value on the generated list in the cell now. We repeat this step until the current cell has a valid value placed inside it.
6. We stop when we reach the 81st cell (the last cell in a Sudoku puzzle) and have placed a valid value.
7. The puzzle has now been solved
8. Stop.

## **Sudoku Validator**

The program itself takes care of the validity of the sudoku. If there is no possible solution, you will get a message.

## **Sudoku Generator**

The program will generate a random sudoku to solve. A toughness parameter has to be entered which will decide how tough the sudoku would be to solve. Toughness ranges from 1-9 with 1 being the easiest and 9 the toughest.

Here's a generated sudoku with toughness 4

```
 -------------------
 0 0 0  6 0 0  0 7 0
 0 9 0  0 0 0  0 0 0
 0 0 0  0 0 0  0 0 0

 0 0 0  0 0 2  3 0 0
 3 0 0  4 9 0  0 5 0
 0 0 8  0 7 0  2 0 0

 0 0 0  0 1 0  9 0 0 
 4 0 0  0 0 0  0 0 0
 0 2 0  0 0 0  0 0 0
 -------------------
```

## **Future Direction**

Right now, the Sudoku Solver Suite is just a CLI application with a I/O interface. However, implementing it visually with OpenCV would be a great idea and fun to work with.

## **Tools Used**

- Visual Studio Code
- GNU G++17 v7.3.0 compiler

<br><br>

*Thank you for reading me!*