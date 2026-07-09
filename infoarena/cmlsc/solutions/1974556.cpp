#include <iostream>
#include <fstream>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int a[1025],b[1025],c[1025][1025],t[1025];
int M,N;
void cmlsc(int a[],int b[]){
 for(int i=1;i<=M;i++)
  for(int j=1;j<=N;j++)
   if(a[i]==b[j])c[i][j]=c[i-1][j-1]+1;
   else c[i][j]=max(c[i-1][j],c[i][j-1]);
}

void traseu(){
 int lg=c[M][N];
 int i=M,j=N;
 while(lg--){
 while(a[i]!=b[j] && c[i][j]==c[i-1][j]){i--;}
 while(a[i]!=b[j] && c[i][j]==c[i][j-1]){j--;}
 t[lg]=a[i];
 i--;j--;
 }
 for(int i=0;i<c[M][N];i++)
  g<<t[i]<<' ';
}


int main(){
 f>>M>>N;
 for(int i=1;i<=M;i++)f>>a[i];
 for(int i=1;i<=N;i++)f>>b[i];
 cmlsc(a,b);
 g<<c[M][N]<<'\n';
 traseu();
}
