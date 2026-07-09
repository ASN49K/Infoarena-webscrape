#include <stdio.h>

int a[1025],b[1025],m,n;
int max[1025][1025];


int maximul(int x,int y){
   if(x>y)return x;
   return y;
}

FILE *fout=fopen("cmlsc.out","w");
void recovery(int i,int j){
       if(i>0&&j>0)
       if(a[i]==b[j]){
          recovery(i-1,j-1);
          fprintf(fout,"%d ",a[i]);
       }else{
          if(max[i-1][j]>max[i][j-1]){
             recovery(i-1,j);             
          }
          else recovery(i,j-1);
       }
   }  

int main(){
  FILE *fin=fopen("cmlsc.in","r");
  fscanf(fin,"%d%d",&m,&n);
  int i,j;
  for(i=1;i<=m;i++)
     fscanf(fin,"%d",&a[i]);
  
  for(i=1;i<=n;i++)
     fscanf(fin,"%d",&b[i]);
  
  /*definesc max[i][j]= lungimea maxima a celui mai lung subsir comun, stiind ca se considera 
  numai primele i elemente din primul sir, si numai primele j elemente din cel de-al doilea
  */
  for(i=0;i<=m;i++)max[i][0]=0;
  for(i=0;i<=n;i++)max[0][i]=0;
  
  for(i=1;i<=m;i++){
     for(j=1;j<=n;j++){
        if(a[i]==b[j]){
            max[i][j]=max[i-1][j-1]+1;
        }else{
            max[i][j]=maximul(max[i-1][j],max[i][j-1]);
        }
     }
  }

  fprintf(fout,"%d\n",max[m][n]);
  //acum vreau sa stiu si care sunt elementele comune
  recovery(m,n);
  fprintf(fout,"\n");
return 0;
}
