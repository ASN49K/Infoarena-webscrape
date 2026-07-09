#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    short V[1000][1000];
    short A[1000];
    short B[1000];
    short Ossz[1000];
    int n,m;
    int i,j;
    ifstream be;
    be.open("cmlsc.in");
    be >> n;
    be >> m;
    for(i=1;i<=n;i++)
    {
    be >> A[i];
    Ossz[i]=0;
    }
    for(i=1;i<=m;i++)
    be >> B[i];
    be.close();
    for(i=0;i<=n;i++)
    {
     for(j=0;j<=m;j++)
     {
      if(i==0 || j==0)
       V[i][j]=0;
      else
      {
       if(V[i-1][j]>=V[i][j-1])
       V[i][j]=V[i-1][j];
       else
       V[i][j]=V[i][j-1];
       if(A[i]==B[j])
       V[i][j]++;
      }
     }
     }
     int k=0;
     i=n;
     j=1;
     while((V[i][j] || A[i]!=B[j]) && (n && m))
     {
      i=n;
      j=1;
     while(A[i]!=B[j] && j<m)
     {
      j++;
     }

      if(j==m)
      {
      while(A[i]!=B[j] && i>1)
      {
       i--;
      }
      }

     if(A[i]==B[j])
     {
     Ossz[k]=A[i];
     k++;
     }

     n=n-i-1;

     if(n==-1)
     n=i-1;

     m=m-j-1;

     if(m==-1)
     m=j-1;
     }
     ofstream ki;
     ki.open("cmlsc.out");
     ki << k << endl;
     for(i=k-1;i>=0;i--)
     {
      ki << Ossz[i] << " ";
     }
     ki.close();

    return 0;
}
