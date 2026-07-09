#include <stdio.h>

int main() {
	int vector1[13] = {0, 0, 0, 1, 0, 2, 0, 1, 1, 3, 5, 99, 77};
		// 1 1 2 1 22 13 15/12
	int vector2[13] = {0, 0, 0, 0, 1, 2, 3, 1, 1, 55, 44, 66, 77};
	int n1 = 13;
	int n2 = 13;
	int i, x, m;
	int comune1[n1];
	int comune2[n2];
	int sir1[n1];
	int lngSir1 = 0;
	int sir2[n2];
	int lngSir2 = 0;
	int find1, find2;
	int last1 = -1;
	int last2 = -1;
	int nrcom1 = 0;
	int nrcom2 = 0;

	for(i=0; i<n1; i++) {    // COMUNE 1 SIR
		for(x=0; x<n2; x++) {
			if(vector1[i] == vector2[x]) {
				comune1[nrcom1++] = vector1[i];
				break;

			}
		}
	}

	for(i=0; i<nrcom1; i++) {
		find1 = 0;
		find2 = 0;
		for(x=0; x<n1; x++) {
			if(comune1[i] == vector1[x] && x > last1) {
				find1 = 1;
				break;
			}
		}

		for(m=0; m<n2; m++) {
			if(comune1[i] == vector2[m] && m > last2) {
				find2 = 1;
				break;
			}
		}

		if(find1 && find2) {
			sir1[lngSir1++] = comune1[i];
			last1 = x;
			last2 = m;
		}

	}
	// COMUNE 2 SIR

	for(i=0; i<n2; i++) {
		for(x=0; x<n1; x++) {
			if(vector2[i] == vector1[x]) {
				comune2[nrcom2++] = vector2[i];
				break;

			}
		}
	}

	last1 = -1;
	last2 = -1;
	for(i=0; i<nrcom2; i++) {
		find1 = 0;
		find2 = 0;
		for(x=0; x<n1; x++) {
			if(comune2[i] == vector1[x] && x > last1) {
				find1 = 1;
				break;
			}
		}

		for(m=0; m<n2; m++) {
			if(comune2[i] == vector2[m] && m > last2) {
				find2 = 1;
				break;
			}

		}

		if(find1 && find2) {
			sir2[lngSir2++] = comune2[i];
			last1 = x;
			last2 = m;
		}
	}


	for(i=0; i<lngSir1; i++) {
		printf("%d ", sir1[i]);
	}
	printf("\n");
	for(i=0; i<lngSir2; i++) {
		printf("%d ", sir2[i]);
	}






	return 0;
}
