# Sudoku-Solver

Above code is a CPP program that :

Takes a partially filled-in grid and attempts to assign values to all unassigned locations in such a way to meet the 

requirements for Sudoku solution (non-duplication across rows, columns,and boxes). 

The function operates via recursive backtracking: it finds an unassigned location with the grid and then considers all digits from 1 to 9 in a loop. If a digit is found that has no existing conflicts, tentatively assign it and recur to attempt to fill in rest of grid. 

If this was successful, the puzzle is solved. 

If not, unmake that decision and try again. 

If all digits have been examined and none worked out, return false to backtrack to previous decision point.
