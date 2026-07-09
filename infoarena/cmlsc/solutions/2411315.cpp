#include <iostream>
#include <vector>
FILE * fin= fopen("cmlsc.in","r");
FILE * fout= fopen("cmlsc.out","w");


int n,m;
int v1[1024];
int rez[1024][1024];
int p[1024][1024];
bool vis[1024][1024];
int v2[1024];
std::vector<int> v;

int LCS(int x, int y, std::vector<int> &s)
{
  if(x==0 || y==0) return 0;
  else if (v1[x-1]==v2[y-1])
  {
  //  std::cout<<v1[x-1]<<" ";
    if(!vis[x-1][y-1])
    {
      rez[x-1][y-1]= LCS(x-1,y-1,s);
     // vis[x-1][y-1]=true;
      s.push_back(v1[x-1]);
    }
    rez[x][y]= rez[x-1][y-1]+1;
    return rez[x][y];
  }
  std::vector<int> v1;
  std::vector<int> v2;
  rez[x][y-1]= LCS(x,y-1,v1);
  rez[x-1][y]= LCS(x-1,y,v2);
  if(rez[x][y-1]> rez[x-1][y])
  {
    rez[x][y]=rez[x][y-1];
    s.insert(s.end(),v1.begin(),v1.end());
  }
  else
  {
    rez[x][y]=rez[x-1][y];
    s.insert(s.end(),v2.begin(),v2.end());
  }
  return rez[x][y];
}
int main()
{
  fscanf(fin,"%d %d",&n,&m);
  for(int i=0;i<n;i++)
    fscanf(fin,"%d",&v1[i]);
  for(int i=0;i<m;i++)
    fscanf(fin,"%d",&v2[i]);
  fprintf(fout,"%d\n",LCS(n,m,v));
  
  for(int i=0;i<(int)v.size();i++)
    fprintf(fout,"%d ",v[i]);
}
