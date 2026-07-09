#include <cstdio>




int maxim (int a, int b){
	if (a>b) {return a;}
	else return b;	
}


 int a[1025], b[1025], i, j, m, n,sir[1025],k; 
 int matrix[1025][1025]={0};
int main () {

 FILE *in,*out;
 in=fopen("cmlsc.in", "rt");
 out=fopen("cmlsc.out", "w+");

 fscanf(in, "%d",&m);
 fscanf(in, "%d",&n);
 //Citire vectori
 for (i=1; i<=m; i++){
 		fscanf(in, "%d",&a[i]);
 }
 
  for (i=1; i<=n; i++){
 		fscanf(in, "%d",&b[i]);
 		matrix [0][i]=0;
 }
 
 // Matrix rezolvare
 for (i=1; i<=m; i++) {
 	for (j=1; j<=n; j++){
 		if (a[i]==b[j]) {matrix[i][j]=matrix[i-1][j-1]+1;}
 		else {matrix[i][j]=maxim(matrix[i-1][j], matrix[i][j-1]);}
 	}
 	
 }

fprintf (out, "%d\n", matrix[m][n]);
k=0;
i=m; j=n;
while (k<matrix[m][n]){
	if (a[i]==b[j]) {sir[++k]=a[i]; i--; j--;}
	else if (matrix[i-1][j]<matrix[i][j-1]) {j--;}
	else {i--;}
	}

for (i=matrix[m][n]; i>=1; i--){ fprintf(out, "%d ", sir[i]);}


 
 return 0;
}
