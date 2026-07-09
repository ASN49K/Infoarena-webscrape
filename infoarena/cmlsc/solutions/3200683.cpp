
#include <fstream>
#include <vector>
using namespace std;
ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");
int n,m;
vector<int> A,B;
int matrice[1025][1025];
int k;
void functie(int x,int y)
{
    if(k)
     if(A[x]==B[y])
         {
             k--;
             functie(x-1,y-1);
             cout<<A[x]<<" ";
             return;
         }
    else
           if(matrice[x-1][y]>matrice[x][y-1])
               functie(x-1,y);
            else
               functie(x,y-1);
}
int main()
{
    cin>>n>>m;
    A.resize(n+1);
    B.resize(m+1);
    for(int i=1;i<=n;i++)
      cin>>A[i];
    for(int j=1;j<=m;j++)
      cin>>B[j];
    for(int i=1;i<=n;i++)
       for(int j=1;j<=m;j++)
           if(A[i]==B[j])
              matrice[i][j]=matrice[i-1][j-1]+1;
            else
              matrice[i][j]=max(matrice[i-1][j],matrice[j][i-1]);
    cout<<matrice[n][m]<<'\n';
    k=matrice[n][m];
    functie(n,m);
    return 0;
}
