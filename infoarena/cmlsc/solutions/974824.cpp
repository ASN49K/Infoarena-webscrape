#include<stdio.h>
#include<stdlib.h>

#define NMAX 1025

struct MatRara{
		int l, c;
		int val;
	};

int partitie(struct MatRara *vect, int p, int q){
	struct MatRara pivot = vect[q];

	while(p < q){
		while(vect[p].c < pivot.c)
			p++;

		while(vect[q].c > pivot.c)
			q--;

		if(vect[p].c == vect[q].c)
			p++;
		else
			if(p < q){
				struct MatRara aux = vect[p];
				vect[p] = vect[q];
				vect[q] = aux;
			}

		}

	return q;
}

void QuickSort(struct MatRara *vect, int p, int q){
	if(p < q){
		int r = partitie(vect, p, q);
		QuickSort(vect, p, r-1);
		QuickSort(vect, r+1, q);
	} 
}

int main(){
	int N, M, i, j, dim, *ok;
	struct MatRara V[NMAX];
	int A[NMAX], B[NMAX];
	FILE *pf, *pg;
	struct MatRara x, y;
	int dmax, aux, sup, inf, m;

	ok = new int[NMAX];


	pf = fopen("cmlsc.in", "r");
	pg = fopen("cmlsc.out", "w");
	fscanf(pf,"%d %d", &M, &N);

	for(i = 1; i <= M; i++)
		fscanf(pf, "%d ", &A[i]);

	for(i = 1; i <= N; i++)
		fscanf(pf, "%d ", &B[i]);

	dim = 0;
	if(M > N)
		for(i = 1; i <= M; i++){
			for(j = 1; j <= N; j++)
				if(B[j] == A[i] && ok[j] == 0){
					dim++;
					V[dim].l = i;
					V[dim].c = j;
					V[dim].val = A[i];
					ok[j] = 1;
					//break;
				}
		}
	else
		for(i = 1; i <= N; i++){
			for(j = 1; j <= M; j++)
				if(B[i] == A[j] && ok[j] == 0){
					dim++;
					V[dim].l = i;
					V[dim].c = j;
					V[dim].val = B[i];
					ok[j] = 1;
					//break;
				}
		}

	QuickSort(V, 1, dim);

	i = 1;
	j = 2;
	dmax = 0;
	
	while(j <= dim){
		x = V[i];
		y = V[j];
		m = i;
		i++;
		j++;
		aux = 1;

		while(j<=dim && x.l < y.l && x.c != y.c){
			aux++;
			x = V[i];
			y = V[j];
			i++;
			j++;
		}

		if(aux > dmax){
			dmax = aux;
			inf =  m;
			sup = inf + dmax - 1;
		}
	}

	fprintf(pg, "%d\n", dmax); 
	for(i = inf; i <= sup; i++)
		fprintf(pg,"%d ", V[i].val);
		
	fclose(pf);
	fclose(pg);
	
	return 0;
}		
