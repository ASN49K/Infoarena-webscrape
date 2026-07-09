#include <fstream>
using namespace std;
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");
int n, m, s[1024], t[1024], LCS[1024][1024], i, j, k, r[1024];
int main()
{
    in >> n >> m;
    for(i = 1; i <= n; ++i)
        in >> s[i];
    for(j = 1; j <= m; ++j)
        in >> t[j];
    for(i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            if(s[i]==t[j])
                LCS[i][j]=LCS[i-1][j-1]+1;
            else
                LCS[i][j]=max(LCS[i-1][j],LCS[i][j-1]);
    out << LCS[n][m] << "\n";
    i=n,j=m;
    while(i>0&&j>0)
    {
        if(s[i] == t[j])
        {
            r[k++]=s[i];
            --i,--j;
        }
        else if(LCS[i][j-1] > LCS[i-1][j])
            --j;
        else
            --i;
    }
    for(i = k-1; i >= 0; --i)
        out << r[i] << ' ';
    return 0;
}
