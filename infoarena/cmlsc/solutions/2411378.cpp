#include <iostream>
#include <vector>
FILE * fin= fopen("cmlsc.in","r");
FILE * fout= fopen("cmlsc.out","w");


int n,m;
int v1[1024];
int rez[1024][1024];
bool vis[1024][1024];
int v2[1024];

int LCS(int x, int y)
{
  if(x==0 || y==0) return 0;
  else if (v1[x-1]==v2[y-1])
  {
  //  std::cout<<v1[x-1]<<"\n";
    if(!vis[x-1][y-1])
    {
      rez[x-1][y-1]= LCS(x-1,y-1);
      vis[x-1][y-1]=true;
    }
    rez[x][y]= rez[x-1][y-1]+1;
    return rez[x][y];
  }
  std::vector<int> v1;
  std::vector<int> v2;
  if(!vis[x][y-1])
  {
    rez[x][y-1]= LCS(x,y-1);
    vis[x][y-1]=true;
  }
  if(!vis[x-1][y])
  {
    rez[x-1][y]= LCS(x-1,y);
    vis[x-1][y]=true;
  }
  rez[x][y]=std::max(rez[x][y-1],rez[x-1][y]);
  return rez[x][y];
}

void write(int x,int y)
{
 // std::cout<<x<<" "<<y<<" "<< v1[x-1]<<" "<<v2[y-1]<<"\n";
  if(x<1 || y<1) return;
  if(v1[x-1]==v2[y-1])
  {
    write(x-1,y-1);
    fprintf(fout,"%d ",v1[x-1]);
  }
  else
  {
    if(rez[x-1][y] > rez[x][y-1])
      write(x-1,y);
    else
      write(x,y-1);
  }
}

int main()
{
  fscanf(fin,"%d %d",&n,&m);
  for(int i=0;i<n;i++)
    fscanf(fin,"%d",&v1[i]);
  for(int i=0;i<m;i++)
    fscanf(fin,"%d",&v2[i]);
  fprintf(fout,"%d\n",LCS(n,m));
  write(n,m);
}

/*
 * 
  for(int i=0;i<=n;i++)
  {
    for(int j=0;j<=m;j++)
      std::cout<<rez[i][j]<<" ";
    std::cout<<"\n";
  }*/
