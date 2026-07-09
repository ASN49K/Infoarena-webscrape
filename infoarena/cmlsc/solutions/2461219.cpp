#include <iostream>
#include <fstream>
#include <stack>
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int n,m;
int v1[1024],v2[1024];
stack<int> s;
int d[1024][1024];

int main()
{
  fin>>n>>m;
  for(int i=0;i<n;i++)
    fin>>v1[i];
  for(int i=0;i<m;i++)
    fin>>v2[i];
  for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
      d[i][j]=(v1[i-1]==v2[j-1])?d[i-1][j-1]+1:max(d[i-1][j],d[i][j-1]);
  fout<<d[n][m]<<"\n";
  int i=n,j=m;
  while(i>0&&j>0)
  {
    if(v1[i-1]==v2[j-1])
    {
      s.push(v1[i-1]);
      i--;
      j--;
    }
    else if(d[i-1][j]>d[i][j-1]) i--;
    else j--;
  }
  while(!s.empty())
  {
    fout<<s.top()<<" ";
    s.pop();
  }
}
