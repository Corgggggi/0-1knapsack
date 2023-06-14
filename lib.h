#include <stdio.h>
#include <stdlib.h>
#define MAXLENGTH 100
#define MAXSIZE 100

/*
intput: two integers a and b
output: the maximum of a and b
*/
int max(int a, int b);

/*
intput: the number of items n, the capacity of the knapsack W, the array of weights, the array of values, the matrix V, the current item i, the current weight w, the current solution, the size of the current solution
output: the optimal solution
*/
void optimalSolutions(int n, int W, int weight[], int value[], int V[][MAXSIZE], int i, int w, int solution[], int *solsize);

/*
input: the number of items n, the capacity of the knapsack W, the array of weights, the array of values
output: the optimal value of the knapsack problem
*/
void knapsack(int W, int weight[], int value[], int n);

/*
input: the file pointer, the pointer of the capacity of the knapsack
*/
void readW(char *filename, int *W);

/*
input: the file pointer, the pointer of the number of items
*/
void readN(char *filename, int *N);

/*
input: the file pointer, the pointer of the array of values, the number of items
*/
void readValues(char *filename, int *values, int N);

/*
input: the file pointer, the pointer of the array of weights, the number of items
*/
void readWeights(char *filename, int *weights, int N);
