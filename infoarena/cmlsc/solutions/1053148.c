#include <stdio.h>

#define max(a,b) ((a>b)?a:b)

void citireSir(int **a, int n){
	int i;
	*a = malloc((n + 1) * sizeof(int));
	for (i = 1; i <= n; ++i){
		scanf("%d", &(*a)[i]);
	}
}

void citire(int **a, int **b, int *n, int*m){
	freopen("cmlsc.in", "r", stdin);
	scanf("%d %d", &*n, &*m);
	citireSir(&(*a), *n);
	citireSir(&(*b), *m);
}

int cautaInSirConditie(int *a, int n, int (*f)(int, int)){
	int ceVreau;
	int i = 1;
	ceVreau = a[i];
	for (; i < n; ++i){
		if ((*f)(a[i], ceVreau) == 1){
			ceVreau = a[i];
		}
	}
	return ceVreau;
}

int maxim(int a, int b){
	if (a > b){
		return 1;
	}
	return 0;
}

int minim(int a, int b){
	if (a < b){
		return 1;
	}
	return 0;
}

void rez(int ***sol, int *a, int *b, int n, int m){
	int i;
	int j;
	*sol = malloc((n + 1) * sizeof(int*));
	for (i = 0; i <= n; ++i){
		(*sol)[i] = malloc((m + 1) * sizeof(int *));
	}
	for (i = 0; i <= n; ++i){
		(*sol)[i][0] = 0;
	}
	for (i = 0; i <= m; ++i){
		(*sol)[0][i] = 0;
	}
	for (i = 1; i <= n; ++i){
		for (j = 1; j <= m; ++j){
			if (a[i] == b[j]){
				(*sol)[i][j] = 1 + (*sol)[i - 1][j - 1];
			}
			else{
				(*sol)[i][j] = max((*sol)[i - 1][j], (*sol)[i][j - 1]);
			}
		}
	}
	printf("%d\n", (*sol)[n][m]);

}

void afisSubsir(int **sol,int *a, int *b, int i, int j){
	if (i == 0 || j == 0){
		return;
	}
	if (a[i] == b[j]){
		afisSubsir(sol, a, b, i - 1, j - 1);
		printf("%d ", a[i]);
		return;
	}
	if (sol[i - 1][j] > sol[i][j - 1]){
		afisSubsir(sol, a, b, i - 1, j);
		return;
	}
	else{
		afisSubsir(sol, a, b, i, j - 1);
		return;
	}
}

int main(){
	int *a = NULL;
	int *b = NULL;
	int **sol = NULL;
	int n;
	int m;
	freopen("cmlsc.out", "w", stdout);
	citire(&a, &b, &n, &m);
	rez(&sol, a, b, n, m);
	afisSubsir(sol, a, b, n, m);
	//printf("minim: %d\n", cautaInSirConditie(a, n, &minim));
	//printf("maxim: %d\n", cautaInSirConditie(a, n, &maxim));

	return 0;
}