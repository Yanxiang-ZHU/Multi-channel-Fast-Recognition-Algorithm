#include <stdio.h>
#include <math.h>
#include <iostream>


int init(int* solution) {
	for (int i = 0; i < 10; i++) {
		solution[i] = 0;
	}

	return 1;
}

int get_parameter(int *T, int *L, int *R) {
	scanf_s("%d\n", T);
	char tmp_char = '\n';
	
	for (int index = 0; index < *T; index++) {
		scanf_s("%d%d", (L + index), (R + index));
		if(getchar()=='\n');
	}

	return 1;
}

int index_solve(int C) {
	int k = 0;
	for (int i = 1; i <= sqrt(C); i++) {
		if (C % i == 0 && ((C / i) + i) % 2 == 0 && ((C / i) + i)/2 >= sqrt(C)) {
			k++;
		}
	}
	return k;
}

int output(int* solution, int* T) {
	for (int index = 0; index < *T; index++) {
		printf("%d\n", solution[index]);
	}

	return 1;
}

int main() {
	int T; // 1-10
	int L[10], R[10];
	long long B, C;

	// parameters I defined
	int i; // for T loop
	long long j; // for C loop
	int solution[10];

	init(solution);

	if (get_parameter(&T, L, R)) {  // get the parameter successfully
		for (i = 0; i < T; i++) {
			// loop for one question
			for (j = L[i]; j <= R[i]; j++) {
				// loop for specific C
				// first I need it to have a solution, only consider B > sqrt(C)
				// -2B = integer + x, C = integer(-) * x(-)
				solution[i] += index_solve(j);
			}
		}
	}

	if (output(solution, &T)) {
		return 0;
	}
}
