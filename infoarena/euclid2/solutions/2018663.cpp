#include <stdio.h>


//InfoArena
//Euclid

int n, A, B;

int cmmdc(int a, int b) {
	if (a < b) {
		int aux = a;
		a = b;
		b = aux;
	}	
	while (a % b != 0) {
		int reminder = a % b;
		a = b;
		b = reminder;
	}
	return b;
}


int main() {
	freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);

	scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &A, &B);
        printf("%d\n", cmmdc(A, B));
    }        
	return 0;
}

