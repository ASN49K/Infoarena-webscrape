#include <stdio.h>
#include <stdlib.h>
int v[100], u[100], sir[100], sol[100], n, m, i, j, lmax;

void ok(int nr){
	j=0;
	for(i=0; i<=nr && j<m; i++)
		while(j<m && sir[i]!=u[j])
			j++;
	return j<m;
}

void bk(int nivel, int lin){
	///folosim nivel  ca sa stim unde am ramas in v
	///folosim lin ca sa stim unde am ramas in completarea sirurului pe care il verificam
	if(nivel==n){///daca am ajuns la top
		if(ok(lin))
			if(lin>lmax){
				lmax=lin;
				for(i=0; i<=lin; i++)
					sol[i]=sir[i];
			}
		return ;
	}
	///nu folosim v[nivel]
	bk(nivel+1, lin);
	///folosim v[nivel]
	sir[lin+1]=v[nivel];
	bk(nivel+1, lin+1);
}

int main(){
	FILE *fin, *fout;
	fin=fopen("cmlsc.in", "r");
	fout=fopen("cmlsc.out", "w");
	fscanf(fin, "%d%d", &n, &m);
	for(i=0; i<n; i++)
		fscanf(fin, "%d", &v[i]);
	for(i=0; i<m; i++)
		fscanf(fin, "%d", &u[i]);
	bk(0, -1);
	for(i=0; i<=lmax; i++)
		fprintf(fout, "%d ", sol[i]);
	fclose(fin);
	fclose(fout);
	return 0;
}