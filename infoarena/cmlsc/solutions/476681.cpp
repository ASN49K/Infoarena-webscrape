#include <cstdio>

FILE*f=fopen("cmlsc.in","r");
FILE*g=fopen("cmlsc.out","w");

int vl1,vl2,v1[1025],v2[1025];
int c[1025][1025],i,j;
char b[1025][1025];
	

void citire(){
	
	fscanf(f,"%d %d",&vl1,&vl2);
	
	for(int i=1;i<=vl1;i++)
		fscanf(f,"%d",&v1[i]);
	
	for(int i=1;i<=vl2;i++)
		fscanf(f,"%d",&v2[i]);
}

void cmlsc2(){

	for(i=vl1;i;i--) 
		c[i][0]=0;
	for(i=vl2;i;i--) 
		c[0][i]=0;
	for(i=1;i<=vl1;i++){
		for(j=1;j<=vl2;j++){
			if(v1[i]==v2[j]){
				c[i][j]=c[i-1][j-1]+1;
				b[i][j]=2;										//2 e \, 1 e <-, 3 e |
			}
			else if(c[i-1][j]>=c[i][j-1]){
				c[i][j]=c[i-1][j];
				b[i][j]=3;
			}
			else {
				c[i][j]=c[i][j-1];
				b[i][j]=1;
			}
		}
	}
	
}

void scriecmlsc(int i,int j){
	if(i&&j){
		if(b[i][j]==2){
			scriecmlsc(i-1,j-1);
			fprintf(g,"%d ",v1[i]);
		}
		else if(b[i][j]==1){
			scriecmlsc(i,j-1);
		}
		else 
			scriecmlsc(i-1,j);
	}
}

int main(){
	
	citire();
	cmlsc2();
	fprintf(g,"%d\n",c[vl1][vl2]);
	scriecmlsc(vl1,vl2);
	
	fclose(f);
	fclose(g);
	return 0;
}
