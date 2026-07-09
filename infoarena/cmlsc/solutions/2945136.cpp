#include <fstream>

using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int c[1025][1025],sol[1025];
int main()
{
    int n,m,a[1025],b[1025];
    fin>>n>>m;
    for(int i=1;i<=n;i++)
        fin>>a[i];
    for(int i=1;i<=m;i++)
        fin>>b[i];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        if(a[i]==b[j]) c[i][j]=c[i-1][j-1]+1;
        else c[i][j]=max(c[i-1][j],c[i][j-1]);
   fout<<c[n][m]<<"\n";
     int i=n,j=m,k=1;
    while(c[i][j]){
        if(a[i]==b[j]){
            k++;
            sol[k]=a[i];
            i--;
            j--;
        }
        else{
            if(c[i-1][j]>c[i][j-1])
                i--;
            else
                j--;
        }
    }
    for(i=k;i>=2;i--)
       fout<<sol[i]<<" ";
    return 0;
}
