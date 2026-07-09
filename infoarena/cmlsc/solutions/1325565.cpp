#include <cstdio>
using namespace std;

int v[1025][1025], a[1025], b[1025], sol[1025];
int maxx(int a, int b)
{
    if(a>b) return a;
    return b;
}
int main()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    int n, m;
    fin>>n>>m;
    for(int i=1; i<=n; i++)
        fin>>a[i];
    for(int j=1; j<=m; j++)
        fin>>b[j];

    for(int i=0; i<=n; i++)
        for(int j=0; j<=m; j++)
            if(i==0 || j==0) v[i][j]=0;
            else if(a[i]==b[j]) v[i][j]=v[i-1][j-1]+1;
            else v[i][j]=maxx(v[i][j-1], v[i-1][j]);

    int sl=0, i=1, j=1;
    while(i<=n && j<=m)
    {
        if(v[i][j]>sl){
            sl++;
            if(n<m){
                sol[sl]=a[i];
            } else{
                sol[sl]=b[j];
            }
        }
        if(v[i+1][j+1]>sl){
            i++; j++;
        } else if(n>m) i++;
        else j++;
    }
    fout<<sl<<endl;
    for(int i=1; i<=sl; i++)
        fout<<sol[i]<<" ";

    fin.close();
    fout.close();
    return 0;
}
