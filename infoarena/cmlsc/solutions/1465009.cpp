#include<iostream>
#include<fstream>
#define NMAX 1025
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int x[NMAX],y[NMAX];
int lcs[NMAX][NMAX];
int n,m;
void read()
{
    fin>>n>>m;

    for(int i=1;i<=n;i++)
      fin>>x[i];
    for(int i=1;i<=m;i++)
        fin>>y[i];


    fin.close();
}

int main()
{
    read();
    for(int i=1;i<=n;i++)
        lcs[i][0]=0;
    for(int i=1;i<=m;i++)
        lcs[0][i]=0;

    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(x[i]==y[j])
            lcs[i][j]=1+lcs[i-1][j-1];
           else
            if(lcs[i-1][j]<=lcs[i][j-1])
            lcs[i][j]=lcs[i][j-1];
           else
            lcs[i][j]=lcs[i-1][j];
int sol[n],ct=0;
   int i=n,j=m;
   while(i&&j)
   {
       if(x[i]==y[j])
        sol[++ct]=x[i],--i,--j;
       else
        if(lcs[i-1][j]<=lcs[i][j-1])
         --j;
       else --i;
   }
  fout<<ct<<" "<<'\n';
  for(i=ct;i>0;i--)
    fout<<sol[i]<<" ";
}
