#include <fstream>
#define ana(n) for(int i = 1;i <= n;i++)
using namespace std;
fstream hai("cmlsc.in",ios::in),pa("cmlsc.out",ios::out);
int a[1025],b[1025],c[1025][1025],v[1025];
int main()
{

    int m,n,i,j;
    hai>>m>>n;
    ana(m)
        hai>>a[i];
    ana(n)
        hai>>b[i];
    for(i = 1; i<=m;i++)
    for(j = 1; j<=n; j++){
        if(a[i] == b[j])
            c[i][j] = 1 + c[i-1][j-1];
        else {
            c[i][j] = max(c[i-1][j],c[i][j-1]);
        }
    }
    int nr;
    nr = 0;
    while(i>0&&j>0){
        if(c[i][j] == c[i-1][j-1]+1){
            v[++nr] = a[i];
            --i;--j;
        }
        else if(c[i][j-1]>c[i-1][j])
            --j;
        else --i;
        }

    pa<<c[m][n];
    pa<<endl;
    for(i = nr; i >= 1;i--)
        pa<<v[i]<<" ";
    pa<<endl;
    return 0;
}
