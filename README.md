# Push Swap

This repository contains my solution for the Push Swap project at 42. The objective of this project is to sort a list of integers passed as a parameter in ascending order, using a limited set of instructions.
Project Description:

## THE PROJECT 

### The Push Swap project challenges us to sort a list of integers with limited resources. We're only allowed to use a predefined set of instructions:

|instructions| description :                                                   |
|------------|-----------------------------------------------------------------|
| sa         | swap the first two elements of the list A.                      |
| sb       | swap the first two elements of the list B.                      |
| ra        | rotate the list A, the first element becomes the last.          |
| rb         | rotate the list B, the first element becomes the last.          |
| rra        | reverse rotate the list A, the last element becomes the first.  |
| rrb        | reverse rotate the list B, the last element becomes the first.  |
| pa         | push the first element of list B to list A.                     |
| pb         | push the first element of list A to list B.                     |

> The challenge lies in sorting the list using as few instructions as possible.

## RADIX ? 

> For lists containing more than 5 elements, I implemented the Radix Sort algorithm to achieve efficient sorting.

### Radix Sort is a non-comparative sorting algorithm that sorts numbers by processing individual digits. Here's how it works:

1. Initialization: Give a first presort with a little math formula.
2. Sort by Least Significant Digit (LSD): Start with the least significant digit and distribute the numbers into the respective buckets based on this digit.
3. Collect: After distributing, collect the numbers back from the buckets, maintaining the order.
4. Repeat: Repeat the process for the next significant digit until all digits are processed.

![alt tag](https://github.com/thomaue/ft_push_swap/blob/main/binary-radix.svg)

### radix visualisation :
[HERE](https://www.youtube.com/watch?v=Tmq1UkL7xeU)

> Radix Sort is efficient because it doesn't rely on comparison between elements, making it suitable for our limited instruction set.

### Simple Sorting for Lists of 5 or Fewer Elements:

For lists containing 5 or fewer elements, I utilized simpler sorting algorithms. These algorithms, although less efficient for larger lists, are suitable for smaller sets due to their simplicity and low overhead.

By employing Radix Sort for larger lists and simpler sorting techniques for smaller lists, I aimed to optimize the sorting process while adhering to the project's constraints.
How to Use:

## WORKING ? 

### To test the sorting functionality, simply compile the program and pass the list of integers as a parameter. The program will output the sorted list along with the sequence of instructions used. 

1. Compile the program:

```bash
$ make
```
2. Run the program with a list of integers:
```bash
$ ./push_swap 4 2 7 1 3
```

