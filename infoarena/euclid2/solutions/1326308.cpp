#include <fstream>
using namespace std;
fstream fin("euclid2.in", ios::in);
fstream fout("euclid2.out", ios::out);

int euclid(int n, int m)
{
    if(m==0) return n;
    euclid(m, n%m);
}
int main()
{
    int n, v[100010], v2[100010];
    fin>>n;
    for(int i=1; i<=n; i++)
        fin>>v[i]>>v2[i];
    for(int i=1; i<=n; i++)
        fout<<euclid(v[i], v2[i])<<"\n";
    fin.close();
    fout.close();
    return 0;
}
