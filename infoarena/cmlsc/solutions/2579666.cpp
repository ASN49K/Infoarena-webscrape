#include <iostream>
#include <fstream>

using namespace std;

const int dim = (int)(1024);
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

int n, m, a[dim], b[dim], c[dim], nr=0;

void cmlsc()
{
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
            if(a[i]==b[j])
            {
                c[++nr]=a[i];
            }
    }
}
int main()
{

    in>>n>>m;
    for(int i=1;i<=n;i++)
        in>>a[i];
    for(int j=1;j<=m;j++)
        in>>b[j];
    cmlsc();
    out<<nr<<'\n';
    for(int i=1;i<=nr;i++)
        out<<c[i]<<' ';


    in.close();
    out.close();
    return 0;
}
