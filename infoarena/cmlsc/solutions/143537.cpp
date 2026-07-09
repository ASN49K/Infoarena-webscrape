#include<fstream>
using namespace std;
int a[1025][1025], x[1025],y[1025],m,n;
char b[1025][1025];
void CMLSC(){
  int i, j;
  //a si b au valori nule
  for(i=1;i<=m;i++)
    for(j=1;j<=n;j++){
      if(x[i]==x[j]) 
        a[i][j]=a[i-1][j-1]+1;
      else if(a[i-1][j]>=a[i][j-1]){
             a[i][j]=a[i-1][j];
             b[i][j]=1;
           } 
           else {
             a[i][j]=a[i][j-1];
             b[i][j]=-1;
           } 
    }
}
void SCRIE(int i, int j){
  if(i&j){
    if(!b[i][j]){
      SCRIE(i-1,j-1);
      g<<x[i]<<' ';
    }
    else if(b[i][j]==1)
           SCRIE(i-1,j);
         else SCRIE(i,j-1);
         
  } 
  else  return;
}
int main(){
  int i, j;
  ifstream f("cmlsc.in");
  f>>m>>n;
  for(i=1;i<=m;i++)
    f>>x[i];
  for(j=1;j<=n;j++)
    f>>y[i];
  f.close();
  CMLSC();
  SCRIE(m,n);
  return 0;
}

