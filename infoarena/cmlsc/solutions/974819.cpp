#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define NMAX 1025

struct MatRara{
		int l, c;
		int val;
	};

int partitie(struct MatRara *vect, int p, int q){
	struct MatRara pivot = vect[q];

	while(p < q){
		while(vect[p].l < pivot.l)
			p++;

		while(vect[q].l > pivot.l)
			q--;

		if(vect[p].c == vect[q].c && vect[p].l == vect[q].l)
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
	struct MatRara V[NMAX], W[NMAX];
	int A[NMAX], B[NMAX];
	FILE *pf, *pg;
	struct MatRara x, y;
	int dmax, aux, sup, inf, m, verif, dim2;

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
			verif = 0;
			for(j = 1; j <= N; j++)
				if(B[j] == A[i]){
					if(verif == 0){
						x.l = i;
						x.c = j;
						x.val = B[j];
						verif = 1;
					}
					else
						if(abs(x.l - x.c) > abs(i - j))
							x.c = j;
				}
			if(verif == 1){		
				dim++;
				V[dim] = x;				
			}
		}
	else
		for(i = 1; i <= N; i++){
			verif = 0;
			for(j = 1; j <= M; j++)
				if(B[i] == A[j]){
					if(verif == 0){
						x.l = i;
						x.c = j;
						x.val = A[j];
						verif = 1;
					}
					else
						if(abs(x.l - x.c) > abs(i - j))
							x.c = j;
				}
			if(verif == 1){		
				dim++;
				V[dim] = x;	
			}			
				
		}

	dim2 = 0;
	for(i = 1; i <= dim; i++){
		if(ok[i] == 0){
			x = V[i];
			for(j = i+1; j <= dim; j++)
				if(x.c == V[j].c){
					if(abs(x.l - x.c) >= abs(V[j].l - V[j].c))
						x = V[j];
					ok[j] = 1;
				}
				
			ok[i] = 1;
			dim2++;
			W[dim2] = x;
		}
	}
	
	QuickSort(W, 1, dim2);

	i = 1;
	j = 2;
	dmax = 0;
	
	while(j <= dim2){
		x = W[i];
		y = W[j];
		m = i;
		i++;
		j++;
		aux = 1;

		while(j<=dim2 && x.c < y.c){
			aux++;
			x = W[i];
			y = W[j];
			i++;
			j++;
		}

		if(aux > dmax){
			dmax = aux;
			inf =  m;
			sup = inf + dmax;
		}
	}

	fprintf(pg, "%d\n", dmax+1); 
	for(i = inf; i <= sup; i++)
		fprintf(pg,"%d ", W[i].val);
		
	fclose(pf);
	fclose(pg);
	
	return 0;
}		
