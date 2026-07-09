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



int X=n;
int Y=m;


while(a[X][Y]!=0){

  if(N[X]==M[Y]){
  k++;
  sol[k]=N[X];
  X--;
  }

  else{

    if(a[X-1][Y]>=a[X][Y-1])
    X--;

    else
    Y--;

  }

}


  


  for(i=k;i>=1;i--)
  fprintf(g,"%d ",sol[i]);


fclose(g);

return 0;
}




