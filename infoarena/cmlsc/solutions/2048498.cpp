#include <iostream>
#include <fstream>
#define MAX 1024
using namespace std;
int find(int v1[],int M,int el)
{
    int j;
    for (j=0; j<M; ++j)
        if (el == v1[j]) return 1;
    return 0;
}

int main ()
{
    ifstream fi("cmlsc.in");
    ofstream g("cmlsc.out");
    int N,M;
    fi >> N >> M;
    int i,v[MAX],v1[MAX];
    for (i=0; i<N; ++i)
        fi >> v[i];
    for (i=0; i<M; ++i)
        fi >> v1[i];
    int f[MAX],q=0;
    for (i=0; i<N; ++i)

        if(find(v1,M,v[i]))
        {
            f[q] = v[i];
            ++q;
        }
        g << q << "\n";
    for (i=0; i<q; ++i)
        g << f[i] << " ";
    return 0;
}
