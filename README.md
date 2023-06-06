# Analysis-of-different-sorting-techniques
Author: Andrei Tircavu

What's the most efficient algorithm for sorting an array of integers?
Let's see.

This project is a demonstration of different sorting algorithms implemented in C. It compares the performance of various sorting algorithms on different input sizes and generates plots using Matlab to visualize the results.

The times will be extracted with the clock() function defined in time.h .
In C, the clock() function is used to measure the processor time consumed by a program. It returns the number of clock ticks elapsed since the program started execution. The clock ticks represent a unit of time defined by the C implementation.

Ensure you have Matlab or Octave installed to generate the plots and a C compiler in order to compile the .c files (e.g: GCC).

The following sorting algorithms are implemented in the "Algorithms.c" file:

- Insertion Sort: An efficient algorithm for sorting small arrays or partially sorted arrays.

- Merge Sort: A divide-and-conquer algorithm that recursively divides the array into two halves, sorts them, and merges them.

- Hybrid Sort: A variation of Merge Sort that switches to Insertion Sort for small subarrays to improve efficiency.

- Quick Sort: A divide-and-conquer algorithm that selects a pivot element and partitions the array around it.

- Randomized Quick Sort: A variation of Quick Sort that selects a random pivot to improve efficiency.

- Median of Three Quick Sort: A variation of Quick Sort that selects the median of three elements as the pivot.

- Tail Recursive Quick Sort: A modified version of Quick Sort that eliminates tail recursion to optimize space usage.

- Optimal Tail Recursive Quick Sort: A further optimized version of Tail Recursive Quick Sort that uses the median of three as the pivot and switchs to Insertion Sort for small subarrays.




When the size of the input array is small, the asymptotic complexity of an algorithm becomes less significant, and the constant factors associated with the algorithm's runtime become more influential. In this context, Insertion Sort's quadratic time complexity of O(N^2) becomes less of a concern for small N.

The O(N^2) complexity of Insertion Sort means that the number of comparisons and swaps grows quadratically with the size of the input array. However, when N is small, the actual number of operations performed by the algorithm is relatively low. In fact, for very small values of N, the constant factors involved in more efficient algorithms may result in higher overhead compared to Insertion Sort.

Therefore, when the input size is small and the focus is on practical performance rather than asymptotic complexity, Insertion Sort can be a suitable choice due to its simplicity and low overhead.

![sorting-algorithms](https://github.com/andreitrcv/Analysis-of-different-sorting-techniques/assets/91255059/a50a12d0-e345-46f7-bbd9-093d1ae0849f)


The performance analysis results demonstrate that the Optimal Tail Recursive Quick Sort algorithm consistently outperforms the other sorting algorithms in terms of efficiency and speed. This algorithm achieves the best performance across various array sizes due to its optimization that consider different behaviour in relation to input size, tail recursion elimination, pseudo-optimal pivot selection, and efficient partitioning, to achieve the best performance. 
