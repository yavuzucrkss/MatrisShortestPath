#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10
void printPathofMatris(int matris[MAX_SIZE][MAX_SIZE], int row, int coloumn);
int min2Matris(int x, int y) {
	if (x < y) return x;
	else return y;
}
int min3Matris(int x, int y, int z) {
	if (x < y && x < z) return x;
	if (y < x && y < z) return y;
	if (z < x && z < y) return z;
}
int main() {
	printf("Yavuz Ucarkus 152120171006\n");
	int row;
	int coloumn;
	int matris[MAX_SIZE][MAX_SIZE];
	printf("Enter number of rows(0 to exit): \n");
	scanf_s("%d", &row);
	if (row == 0) return 0;

	printf("Enter number of coloumns: \n");
	scanf_s("%d", &coloumn);
	printf("\n\n");
	if (row > 10 || coloumn > 10) { printf("The number of rows and columns can be up to 10."); }
	else {
		createMatris(row, coloumn, matris);
		printPathofMatris(matris, row, coloumn);

	}

}

int createMatris(int row, int coloumn, int matris[MAX_SIZE][MAX_SIZE]) {
	srand(time(NULL));

	int min;

	printf("Matris :: \n");
	for (int i = 0; i < coloumn; i++) {

		for (int j = 0; j < row; j++) {

			matris[i][j] = (rand() % 10);
			printf("%d\t", matris[i][j]);
		}
		printf("\n");
	}
	printf("\n");


	return matris;
}

void printPathofMatris(int matris[MAX_SIZE][MAX_SIZE], int row, int coloumn) {


	int weightpath[MAX_SIZE][MAX_SIZE];
	int lastindex = 0;
	int index[MAX_SIZE];
	int minint = 10000;
	int sumofWeighth = 0;

	for (int i = 0; i < coloumn; i++) { //create weightpath

		for (int j = 0; j < row; j++) {
			if (i == 0) { weightpath[i][j] = matris[i][j]; }
			if (i != 0) {
				if (j == 0) {
					weightpath[i][j] = matris[i][j] + min2Matris(weightpath[i - 1][j], weightpath[i - 1][j + 1]);
				}
				else if (j == row - 1) {
					weightpath[i][j] = matris[i][j] + min2Matris(weightpath[i - 1][j], weightpath[i - 1][j - 1]);
				}
				else if (0 < j && j < row - 1) {
					weightpath[i][j] = matris[i][j] + min3Matris(weightpath[i - 1][j], weightpath[i - 1][j - 1], weightpath[i - 1][j + 1]);
				}
			}
		}
	}

	// Begin Weight Path Print
	printf("Weigth Matris :: \n");
	for (int i = 0; i < coloumn; i++) { // print

		for (int j = 0; j < row; j++) {

			if (index[i] == j) {
				printf("[%d]\t", weightpath[i][j]);
				sumofWeighth += weightpath[i][j];
			}
			else
			{
				printf(" %d\t", weightpath[i][j]);
			}
		}
		printf("\n");
	}
	printf("\n");
	//End
	for (int i = coloumn - 1; i >= 0; i--) {
		if (i == coloumn - 1) {
			for (int j = 0; j < row; j++) {
				if (i == coloumn - 1) {
					if (minint > weightpath[i][j]) {
						minint = weightpath[i][j];
					}
				}
			}
			for (int j = 0; j < row; j++) {


				if (minint == weightpath[i][j]) {
					index[i] = j;
					lastindex = j;
				} //
			}
		}
		else {
			{
				if (0 < lastindex && lastindex < row - 1) {
					if (weightpath[i][lastindex] == min3Matris(weightpath[i][lastindex], weightpath[i][lastindex - 1], weightpath[i][lastindex + 1])) {
						index[i] = lastindex;
					}
					else if (weightpath[i][lastindex - 1] == min3Matris(weightpath[i][lastindex], weightpath[i][lastindex - 1], weightpath[i][lastindex + 1]))
					{
						index[i] = lastindex - 1;
						lastindex -= 1;
					}
					else if (weightpath[i][lastindex + 1] == min3Matris(weightpath[i][lastindex], weightpath[i][lastindex - 1], weightpath[i][lastindex + 1])) {
						index[i] = lastindex + 1;
						lastindex += 1;
					}
				}
				else if (lastindex == 0) {
					if (weightpath[i][lastindex] == min2Matris(weightpath[i][lastindex], weightpath[i][lastindex + 1])) {
						index[i] = lastindex;
					}
					else
					{
						index[i] = lastindex + 1;
						lastindex += 1;
					}
				}
				else if (lastindex == row - 1) {

					if (weightpath[i][lastindex] == min2Matris(weightpath[i][lastindex], weightpath[i][lastindex - 1])) {
						index[i] = lastindex;
					}
					else
					{
						index[i] = lastindex - 1;
						lastindex -= 1;
					}
				}
			}
		}

	}

	printf("Minimum weight path of 'Main Matrix' :: \n");
	for (int i = 0; i < coloumn; i++) { // print

		for (int j = 0; j < row; j++) {

			if (index[i] == j) {
				printf("[%d]\t", matris[i][j]);
				sumofWeighth += matris[i][j];
			}
			else
			{
				printf(" %d\t", matris[i][j]);
			}
		}
		printf("\n");
	}
	printf("\nSum of weights: %d", sumofWeighth);
}








