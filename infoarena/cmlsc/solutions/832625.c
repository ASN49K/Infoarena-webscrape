#include <stdio.h>

#define MAX(x,y) (((x)<(y))?(y):(x))

int main(int argc, char* argv[])
{
	int i,j,k,m,n;
	int a[1024],b[1024];
	int l[1024][1024];
	int lasti;

	FILE *fin,*fout;
	fin = fopen("cmlsc.in","r");
	
	fscanf(fin,"%d %d",&m,&n);

	for(i=0;i<m;i++){
		fscanf(fin,"%d",a+i);
	}

	for(j=0;j<n;j++){
		fscanf(fin,"%d",b+j);
	}
	fclose(fin);
		
	for(i=0;i<m;i++)
		for(j=0;j<n;j++){
			if( a[i] == b[j] ){
				if( i == 0 || j == 0 )
					l[i][j] = 1;
				else
					l[i][j] = l[i-1][j-1]+1;
			}
			else{
				if( i==0 && j==0 )
					l[i][j] = 0;
				else if( i==0 )
					l[i][j] = l[i][j-1];
				else if( j==0 )
					l[i][j] = l[i-1][j];
				else
					l[i][j] = MAX(l[i][j-1],l[i-1][j]);
			}
		}	
	int aux[1024];
	
	i=m-1; j=n-1;
	k=l[i][j];
	while(k>0){
		if( a[i] == b[j] ){
			aux[k-1] = a[i];
			k--;
			i--;
			j--;
		}
		else{
			if( l[i-1][j] > l[i][j-1] )
				i--;
			else
				j--;			
		}		
	}
	
	fout = fopen("cmlsc.out","w");
	fprintf(fout,"%d\n",l[m-1][n-1]);
	for(i=0;i<l[m-1][n-1];i++)
		fprintf(fout,"%d ",aux[i]);
	fclose(fout);
}
