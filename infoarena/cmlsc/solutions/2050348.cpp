#include <fstream>
#include <vector>
#define MAX(a,b) a>b?a:b
#define LM 1026

using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

vector <int> v;
int n, m;
int a[LM], b[LM];
int pd[LM][LM];

int main()
{
    fin>>n>>m;
    for (int i=1;i<=n;i++)
         fin>>a[i];
    for (int j=1;j<=m;j++)
         fin>>b[j];
    for (int i=1;i<=n;i++)
         for (int j=1;j<=m;j++)
              if (a[i]==b[j])
                  pd[i][j]=MAX(MAX(pd[i-1][j-1]+1, pd[i-1][j]),pd[i][j-1]);
                  else pd[i][j]=MAX(pd[i][j-1], pd[i-1][j]);
    fout<<pd[n][m]<<'\n';
    for (int i=n, j=m; i>=1&&j>=1;)
         if (a[i]==b[j])
             {v.push_back(a[i]);i--,j--;}
             else
             if (pd[i-1][j]>pd[i][j-1])
                 {
                  i--;
                 }
                 else {j--;}
    for (int i=v.size()-1;i>=0;i--)
         fout<<v[i]<<' ';
    fout<<'\n';
    fin.close();
    fout.close();
    return 0;
}

