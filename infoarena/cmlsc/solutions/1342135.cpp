#include <fstream>
#include <algorithm>
#define NMax 1025

using namespace std;

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

int T[NMax][NMax], v1[NMax], v2[NMax], v3[NMax];

int main()
{
    int n,m,i,j,k=1;

    in>>n>>m;

    for(i = 1; i <= n; ++ i)
        in >> v1[i];
    for(j = 1; j <= m; ++ j)
        in >> v2[j];

    for(i = 1; i <= n; ++ i)
    {
        for(j = 1; j <= m; ++ j)
        {
            if(v1[i]!=v2[j])
                T[i][j] = max(T[i-1][j], T[i][j-1]);
            else
                T[i][j] = max(1+T[i-1][j-1], max(T[i-1][j], T[i][j-1]));
        }
    }
    out << T[n][m] << endl;
    i = n;
    j = m;
    while(i>0 && j>0)
    {
        if(v1[i] == v2[j])
        {
            v3[T[i][j]]=v1[i];
            i--;
            j--;
        }
        else if(T[i-1][j]==T[i][j])
            i--;
        else
            j--;
    }

    for(i = 1;i <= T[n][m]; ++ i)
        out << v3[i] << " ";

    out << endl;

    return 0;
}
