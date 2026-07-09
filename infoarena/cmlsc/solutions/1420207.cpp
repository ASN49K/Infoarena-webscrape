#include <fstream>
#include <vector>
#define Max 1024
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int v[Max],u[Max],mat[Max][Max];
vector<int> sol;
int main()
{
    int m,n,i,j;
    fin>>m>>n;
    for(i=1;i<=m;i++)
      fin>>v[i];
    for(i=1;i<=n;i++)
       fin>>u[i];
     
    for(i=1;i<=m;i++)   
      for(j=1;j<=n;j++)
      {
          if(v[i]==u[j]) mat[i][j]=mat[i-1][j-1]+1;
          else mat[i][j]=max(mat[i-1][j],mat[i][j-1]);
      }
    i=m;j=n;
    while(i>0&&j>0)
    {
        if(v[i]==u[j])
         {sol.push_back(v[i]);
          j--;
          i--;
         }
        else if(mat[i-1][j]<mat[i][j-1])
          j--;
        else i--;
    }
    fout<<sol.size()<<"\n";
    for(i=sol.size()-1;i>=0;i--)
     fout<<sol[i]<<" ";
    
    return 0;
}
