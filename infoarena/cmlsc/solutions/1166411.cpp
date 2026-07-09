#include<fstream>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int M,N,i,j;
int v1[1024],v2[1024],sol[1024],contor;

int main()
{
    f>>M>>N;
    for (i=0;i<M;i++)
    f>>v1[i];
    for (i=0;i<N;i++)
    f>>v2[i];
    for (i=0;i<M;i++)
    for (j=0;j<N;j++)
    if (v1[i]==v2[j])
    {
        sol[contor]=v1[i];
        contor++;
    }
    g<<contor<<'\n';
    for (i=0;i<contor;i++)
    g<<sol[i]<<' ';
    f.close();g.close();
    return 0;
}
