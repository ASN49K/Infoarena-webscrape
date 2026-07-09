#include <fstream>

using namespace std;

ifstream f ("fractii.in");
ofstream g ("fractii.out");

int v[1000001];

int main()
{
    int i,n;
    long long nr=0;


    f>>n;

    for(i=2; i<=n; i++)
        v[i]=i-1;

    for(i=2; i<=n; i++)
    {
        nr+=v[i];

        for(int d=2*i; d<=n; d+=i)
            v[d]-=v[i];

    }

    g<<nr*2+1;

    return 0;
}
