//https://infoarena.ro/problema/cmlsc

#include <fstream>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int main()
{
	int n, m, v[1025], x[1025], s[1025], lmax=0;
	fin >> n >> m;
	int ok = 0;
	for (int i = 1; i <= n; i++)
        fin>>v[i];
    for (int i = 1; i <= m; i++)
        fin>>x[i];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
            if(v[i]==x[j] and v[i]>s[lmax])
                {
                    s[++lmax]=v[i];
                    break;
                }
    }
    fout<<lmax<<endl;
    for(int i=1;i<=lmax;i++)
    fout<<s[i]<<" ";
    return 0;
}

