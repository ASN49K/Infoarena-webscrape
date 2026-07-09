#include <fstream>
#define maxim(a, b) ((a > b) ? a : b)
using namespace std;
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");
int n, m, mx=0, a[1025], b[1025], c[1025], i, j, ma[1025][1025];
int main()
{

    in>>n>>m;
    for(i=1;i<=n;i++)
        in>>a[i];
    for(i=1;i<=m;i++)
        in>>b[i];
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            if(a[i]==b[j])
                ma[i][j]= 1 + ma[i-1][j-1];
            else ma[i][j] = maxim(ma[i-1][j] , ma[i][j-1]);
        }
    }
    i=n;
    j=m;
    while(i>0)
    {
        if(a[i]==b[j])
        {
            mx++;
            c[mx]=a[i];
            i--; j--;
        }
        else if(ma[i-1][j] < ma[i][j-1])j--;
                else i--;
    }
    out<<mx<<'\n';
    for(i=1;i<=mx;i++)
        out<<c[i]<<" ";
    return 0;
}
