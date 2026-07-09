#include <fstream>

using namespace std;
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");
int main()
{
    int n, m, mx=0, a[1025], b[1025], c[1025], i, j, np=0;
    in>>n>>m;
    for(i=0;i<n;i++)
        in>>a[i];
    for(i=0;i<m;i++)
        in>>b[i];
    for(i=0;i<n;i++)
    {
        for(j=np;j<m;j++)
            if(a[i]==b[j])
            {
                c[mx]=a[i];
                mx++;
                np=j;
            }
    }
    out<<mx<<'\n';
    for(i=0;i<mx;i++)
        out<<c[i]<<" ";
    return 0;
}
