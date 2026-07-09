#include<fstream>


using namespace std;


ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int n,m,i,j,mat[1060][1060],a[1026],b[1026];


void afisare(int i,int j){

  if(i==0 || j==0)
   return ;

  if(a[i]==b[j])
  {
      afisare(i-1,j-1);
      g<<a[i]<<" ";

  }
  else
  if(mat[i-1][j]>mat[i][j-1])
      afisare(i-1,j);
   else

      afisare(i,j-1);



}

int main(){



  f>>n>>m;

   for(i=1;i<=n;i++)
     f>>a[i];
   for(j=1;j<=m;j++)
     f>>b[j];

   for(i=1;i<=n;i++)
    for(j=1;j<=m;j++)
       if(a[i]==b[j])
         mat[i][j]=mat[i-1][j-1]+1;
        else
         mat[i][j]=max(mat[i-1][j],mat[i][j-1]);

    g<<mat[n][m]<<endl;
     afisare(n,m);


 return 0;
}
