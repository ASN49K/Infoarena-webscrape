#include<stdio.h>

int n,m,i,j,N[1210],M[1210],a[1211][1211];


int main(){



FILE *f=fopen("cmlsc.in","r");
fscanf(f,"%d %d",&n,&m);

  for(i=1;i<=n;i++)
  fscanf(f,"%d",&N[i]);

  for(i=1;i<=m;i++)
  fscanf(f,"%d",&M[i]);

fclose(f);


   for(i=1;i<=n;i++){
     for(j=1;j<=m;j++){

       if(N[i]==M[j])
       a[i][j]=a[i-1][j-1]+1;

       else{
       a[i][j]=a[i-1][j];

	 if(a[i][j-1]>a[i][j])
	 a[i][j]=a[i][j-1];
       }

     }
   }


FILE *g=fopen("cmlsc.out","w");
fprintf(g,"%d\n",a[n][m]);

int k=0,sol[2222];

int x=n;
int y=m;


  while(a[x][y]!=0){

     if(a[x-1][y-1]==a[x][y]-1){
     k++;
     sol[k]=N[x];
     x--;
     y--;
     }


     else{

       if(a[i][j-1]>a[i-1][j])
       y--;

       else
       x--;

     }

  }


  for(i=k;i>=1;i--)
  fprintf(g,"%d ",sol[i]);


fclose(g);

return 0;
}




