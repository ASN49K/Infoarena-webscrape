#include <iostream>
#include <stdio.h>

#define NMAX 1025

using namespace std;

int table[NMAX][NMAX];

int main()
{
	int N, M;
	int a[NMAX], b[NMAX];

	freopen("cmlsc.in", "r", stdin);
	freopen("cmlsc.out","w", stdout);

	scanf("%d %d", &M, &N);

	for(int i=0 ; i<M ; i++)
		scanf("%d", &a[i]);
	for(int i=0 ; i<N ; i++)
		scanf("%d", &b[i]);

	for(int i=M-1 ; i>=0 ; i--)
		for(int j=N-1 ; j>=0 ; j--){
			if(a[i] == b[j]){
				table[i][j] = table[i+1][j+1] + 1;
			}
			else{
				if(table[i+1][j] > table[i][j+1])
					table[i][j] = table[i+1][j];
				else
					table[i][j] = table[i][j+1];
			}
		}

//print
	printf("%d\n", table[0][0]);

	int i=0, j=0;
	while(i<M && j<N ){
			if(a[i] == b[j]){
				printf("%d ", a[i]);
				i++;
				j++;
			}
			else{
				if(table[i+1][j] > table[i][j+1])
					i++;
				else
					j++;
			}
		}

    return 0;
}
