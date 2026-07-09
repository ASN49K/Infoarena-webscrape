#include <fstream>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int fr[257],v[1025];
int main()
{
    int n,m,i,x,j=1;
    fin >> n >> m;
    for (i=1;i<=n;i++)
    {
        fin >> x;
        fr[x]++;
    }
    for (i=1;i<=m;i++)
    {
        fin >> x;
        if (fr[x]!=0)
        {
            v[j++]=x;
            fr[x]--;
        }
    }
    fout << j-1 << '\n';
    for (i=1;i<j;i++)
    {
        fout << v[i] << " ";
    }

}
