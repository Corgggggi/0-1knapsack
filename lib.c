#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// define the maximum values of input
#define MAXLENGTH 100
#define MAXSIZE 100

// define a matrix to record wheter the solution has been visited
bool visited[MAXLENGTH][MAXSIZE];

int max(int a, int b) {
	// find the maximum value
	return (a > b) ? a : b; 
}

void optimalSolutions(int n, int W, int weight[], int value[], int V[][MAXSIZE], int i, int w, int solution[], int *solsize) {
	if (i == 0 || w == 0) {
		int j;
		// if the case is the optimal solution, print it
	        for (j = 0; j < *solsize; j++) {
	            	printf("%d ", solution[j]);
	        }
	        printf("\n");
	        return;
	    }
	if (V[i][w] == V[i-1][w]) {
		// recursively call the function
	        optimalSolutions(n, W, weight, value, V, i-1, w, solution, solsize);
	}
	if (weight[i-1] <= w && V[i][w] == value[i-1] + V[i-1][w - weight[i-1]]) {
	        solution[*solsize] = i;
	        (*solsize)++;
		// recursively call the function
	        optimalSolutions(n, W, weight, value, V, i-1, w - weight[i-1], solution, solsize);
	        (*solsize)--;
	}
}

void knapsack(int W, int weight[], int value[], int n){
	int w, i, V[MAXLENGTH][MAXSIZE];
	for (w = 0; w <= W; w++){
		V[0][w] = 0;
	}
	for (i = 1; i <= n; i++){
		for (w = 1; w <= W; w++){
			if (weight[i - 1] <= w){
				// determine whether the current item should be picked or not 
				V[i][w] = max(value[i - 1] + V[i - 1][w - weight[i-1]],  V[i-1][w]);
            		}else{
                		V[i][w] = V[i-1][w];
            		}
        	}
    	}
    	int optimal_value = V[n][W];
	// print the optimal value
    	printf("The opt. value is\n%d\n", optimal_value);
    	int solution[MAXLENGTH], solsize = 0;
	// print the optimal solutions
    	printf("The opt. sol(s) are\n");
    	optimalSolutions(n, W, weight, value, V, n, W, solution, &solsize);
}

void readW(char *filename, int *W){
	    FILE *fp;
	    fp = fopen(filename, "r");
	    if (fp == NULL){
	        printf("Error opening file\n");
	        exit(1);
	    }
	    // the first line is the capacity of the knapsack W
	    fscanf(fp, "%d", W);
	    fclose(fp);
}

void readN(char *filename, int *N){
	    FILE *fp;
	    fp = fopen(filename, "r");
	    if (fp == NULL){
	        printf("Error opening file\n");
	        exit(1);
	    }
	    // the number of items in the second line indicates the number of N
	    char line[1024];
	    fscanf(fp, "%s", line);
	    fscanf(fp, "%s", line);
	    int i, numOfComma = 0;
	    for(i = 0; i < strlen(line); i++){
	        if (line[i] == ','){
	            numOfComma++;
	        }
	    }
	    *N = numOfComma + 1;
}

void readValues(char *filename, int *values, int N){
	    FILE *fp;
	    fp = fopen(filename, "r");
	    if (fp == NULL){
	        printf("Error opening file\n");
	        exit(1);
	    }
	    // the items in the second line indicates the values of items
	    char line[1024];
	    fscanf(fp, "%s", line);
	    fscanf(fp, "%s", line);
	    int i;
	    char *token = strtok(line, ",");
	    for(i = 0; i < N; i++){
	        values[i] = atoi(token);
		// the number is separated by comma
	        token = strtok(NULL, ",");
	    }
	    fclose(fp);
}

void readWeights(char *filename, int *weights, int N){
	    FILE *fp;
	    fp = fopen(filename, "r");
	    if (fp == NULL){
	        printf("Error opening file\n");
	        exit(1);
	    }
	    // the items in the third line indicates the weights of items
	    char line[1024];
	    fscanf(fp, "%s", line);
	    fscanf(fp, "%s", line);
	    fscanf(fp, "%s", line);
	    int i;
	    char *token = strtok(line, ",");
	    for(i = 0; i < N; i++){
	        weights[i] = atoi(token);
		// the number is separated by comma
	        token = strtok(NULL, ",");
	    }
	    fclose(fp);
}
