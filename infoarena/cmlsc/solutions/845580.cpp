#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <stack>

using namespace std;

struct Matrix {
	int** items;
	int lines;
	int columns;
};

struct Vector {
	int* items;
	int length;
};

int max(int a, int b) {
	return a > b ? a : b;
}

int min(int a, int b) {
	return a < b ? a : b;
}


void clearMatrix(Matrix* matrix) {
	for(int line=0;line<matrix->lines;line++) {
		for(int column=0;column<matrix->columns;column++) {
			matrix->items[line][column] = 0;
		}
	}
}

Matrix* initMatrix(int lines, int columns) {
	int** matrix = (int**) malloc(lines * sizeof(int*));

	for(int line=0;line<lines;line++) {
		matrix[line] = (int*) malloc(columns * sizeof(int));
	}

	Matrix* resultMatrix = (Matrix*) malloc(sizeof(Matrix));
	resultMatrix->items = matrix;
	resultMatrix->lines = lines;
	resultMatrix->columns = columns;

	clearMatrix(resultMatrix);

	return resultMatrix;
}

void deallocMatrix(Matrix* matrix) {
	for(int line=0;line<matrix->lines;line++) {
		free(matrix->items[line]);
	}

	free(matrix->items);
	free(matrix);
}

void printMatrix(Matrix* matrix) {
	for(int line=0;line<matrix->lines;line++) {
		for(int column=0;column<matrix->columns;column++) {
			printf("%d ", matrix->items[line][column]);
		}

		printf("\n");
	}	
}

void fillMatrix(Matrix* matrix, Vector* firstSequence, Vector* secondSequence) {
	for(int line=1;line<matrix->lines;line++) {
		for(int column=1;column<matrix->columns;column++) {
			
			matrix->items[line][column] = max(matrix->items[line-1][column], 
											  matrix->items[line][column-1]);

			if (firstSequence->items[line-1] == secondSequence->items[column-1]) {
				matrix->items[line][column]++;
			}
		}
	}	
}

int getMaxLCSLen(Matrix* matrix) {
	return matrix->items[matrix->lines-1][matrix->columns-1];
}

void printLCS(Matrix* matrix, Vector* firstSequence, Vector* secondSequence, stack<int>* result, int line, int column) {
	if (matrix->items[line][column] == 0) {
		printf("%d\n", result->size());
		while(!result->empty()) {
			printf("%d ", result->top());
			result->pop();
		}
		return;
	}
	if (firstSequence->items[line-1] == secondSequence->items[column-1]) {
		//printf("%d", firstSequence->items[line-1]);
		result->push(firstSequence->items[line-1]);
		if ((matrix->items[line-1][column] == matrix->items[line][column-1]) &&
		   (matrix->items[line-1][column] == matrix->items[line-1][column-1])) {
			printLCS(matrix, firstSequence, secondSequence, result, line-1, column-1);
		} else {
			int direction = max(matrix->items[line-1][column], matrix->items[line][column-1]);
			if (direction == matrix->items[line-1][column]) {
				//up
				//printf("up\n");
				printLCS(matrix, firstSequence, secondSequence, result, line-1, column);
			} else {
				//left
				//printf("left\n");
				printLCS(matrix, firstSequence, secondSequence, result, line, column-1);
			}
		}
	} else {
		int direction = max(matrix->items[line-1][column], matrix->items[line][column-1]);
		if (direction == matrix->items[line-1][column]) {
			//up
			//printf("up\n");
			printLCS(matrix, firstSequence, secondSequence, result, line-1, column);
		} else {
			//left
			//printf("left\n");
			printLCS(matrix, firstSequence, secondSequence, result, line, column-1);
		}

	}
}

Vector* initVector(int length) {
	Vector* vector = (Vector*) malloc(sizeof(Vector));
	vector->items = (int*) malloc(length * sizeof(int));
	vector->length = length;

	return vector;
}

void readSequence(Vector* sequence) {
	for(int i=0;i<sequence->length;i++) {
		scanf("%d", &sequence->items[i]);
	}
}

void printVector(Vector* vector) {
	for(int i=0;i<vector->length;i++) {
		printf("%d", vector->items[i]);
	}

	printf("\n");
}


int main()
{
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);

	int n;
	int m;

	scanf("%d", &n);
	scanf("%d", &m);

	Matrix* matrix = initMatrix(n + 1, m + 1);

	Vector* firstSequence = initVector(n);
	Vector* secondSequence = initVector(m);

	readSequence(firstSequence);
	readSequence(secondSequence);

	fillMatrix(matrix, firstSequence, secondSequence);
	//printMatrix(matrix);

	//printf("%d\n", getMaxLCSLen(matrix));
	printLCS(matrix, firstSequence, secondSequence, new stack<int>(),matrix->lines-1, matrix->columns-1);

	deallocMatrix(matrix);

	return 0;
}