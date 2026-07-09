#include<iostream>
#include<fstream>
#define NMAX 1025
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int a[NMAX],b[NMAX],s[NMAX][NMAX],sol[NMAX],bst;
int n,m;
void read()
{
    fin>>n>>m;
    for(int i=1;i<=n;i++)
        fin>>a[i];
    for(int i=1;i<=m;i++)
        fin>>b[i];
    fin.close();
}

int main()
{
    read();
   for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
      if(a[i]==b[j])
    s[i][j]=1+s[i-1][j-1];
   else
    s[i][j]=max(s[i-1][j],s[i][j-1]);
   for(int i=n,j=m;j>=1&&i>=1;i,j)
   {
         if(a[i]==b[j])sol[++bst]=a[i],--i,--j;
         else
            if(s[i-1][j]<s[i][j-1])--j;
         else --i;
   }
   fout<<bst<<'\n';
   for(int i=bst;i>=1;i--)
     fout<<sol[i]<<" ";
      return 0;
}
