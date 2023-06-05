# Analysis-of-different-sorting-techniques
Author: Andrei Tircavu

What's the most efficient algorithm for sorting an array of integers?
Let's see.

This project is a demonstration of different sorting algorithms implemented in C. It compares the performance of various sorting algorithms on different input sizes and generates plots using Matlab to visualize the results.

The times will be extracted with the clock() function defined in time.h .
In C, the clock() function is used to measure the processor time consumed by a program. It returns the number of clock ticks elapsed since the program started execution. The clock ticks represent a unit of time defined by the C implementation.

Ensure you have Matlab or Octave installed to generate the plots and a C compiler in order to compile the .c files (e.g: GCC).


-   Insertion Sort     = =>>> O(N^2)
-   Merge Sort         = =>>> O(n*log(n))	
-   Quick Sort         = =>>> O(n*log(n))

* (These complexities are verified in the average cases)



