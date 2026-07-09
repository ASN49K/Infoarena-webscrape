#include <fstream>
#include <algorithm>
using namespace std;

int v[2049], f[1025];
int a, b, c;
int main()
{
    ifstream fin("cmlsc.in");
    ofstream fout("cmlsc.out");
    ios_base::sync_with_stdio(false);
    fin.tie(NULL);
    fout.tie(NULL);

    fin>>a>>b;
    for(int i=0; i<a+b; i++)
        fin>>v[i];
    sort(v, v+a+b);
    for(int i=1; i<a+b; i++)
    {
        if(v[i]==v[i-1])
        {
            f[c]=v[i];
            c++;
        }
    }
    fout<<c<<endl;
    for(int i=0; i<c; i++)
    {
        fout<<f[i]<<' ';
    }

    return 0;
}