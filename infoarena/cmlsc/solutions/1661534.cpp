#include <fstream>
using namespace std;
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");
int n, m, s[1024], t[1024], LCS[1024][1024], r[1024];
int lcs(int i, int j)
{
    if(i < 0 || j < 0) return 0;
    if(LCS[i][j]) return LCS[i][j];
    int q;
    if(s[i]==t[j])
        q = 1+lcs(i-1,j-1);
    else
        q = max(lcs(i-1,j),lcs(i,j-1));
    LCS[i][j] = q;
    return q;
}
int main()
{
    in >> n >> m;
    for(int i = 0; i < n; ++i)
        in >> s[i];
    for(int i = 0; i < n; ++i)
        in >> t[i];
    out << lcs(n-1,m-1) << '\n';
    int i = n-1, j = m-1, k = 0;
    while(i>=0 && j >= 0)
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
