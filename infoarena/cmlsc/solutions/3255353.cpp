#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int tabel[1025][1025]={0};
int A[1025],B[1025];

void sir(int i,int j)
{
  if(tabel[i][j])
  {
    while(tabel[i-1][j-1]==tabel[i][j])
    {
      i-=1;
      j-=1;
    }
    while(tabel[i-1][j]==tabel[i][j])
    {
      i-=1;
    }
    while(tabel[i][j-1]==tabel[i][j])
    {
      j-=1;
    }
    if(tabel[i-1][j-1]==tabel[i][j]-1)
    {
      sir(i-1,j-1);
      cout<<A[i]<<" ";
    }
    else if(tabel[i][j-1]==tabel[i][j]-1)
    {
      sir(i,j-1);
      cout<<A[i]<<" ";
    }
    else
    {
      sir(i-1,j);
      cout<<A[i]<<" ";
    }
  }
}
int main()
{
    int LungA,LungB;
    fin>>LungA>>LungB;

    for(int i=1;i<=LungA;i++)
      fin>>A[i];
    for(int i=1;i<=LungB;i++)
      fin>>B[i];

    for(int i=1;i<=LungA;i++)
    {
      for(int j=1;j<=LungB;j++)
      {
        if(A[i]==B[j])
        {
          tabel[i][j]=tabel[i-1][j-1]+1;
        }
        else
        {
          tabel[i][j]=max(tabel[i-1][j],tabel[i][j-1]);
        }
      }
    }
    fout<<tabel[LungA][LungB]<<endl;;
    sir(LungA,LungB);
    return 0;
}
