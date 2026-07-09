//#include <iostream>
#include<fstream>
//#include<math.h>
//#include<string>
//#include<stack>
//#include<windows.h>
//#include<time.h>
//#include<queue>
using namespace std;
//long long ;
int a[100], b[100], ma[100][100], solutie[100], nr, n, m, i, j;
//stack <int> ;
//string ;
//struct e
//{
//}
//queue <e>;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
inline void citire()
{
    fin >> n >> m;
    for(int i = 1; i <= n; ++i)
    {
        fin >> a[i];
    }
    for(int j = 1; j <= m; ++j)
    {
        fin >> b[j];
    }
}
inline void bordare()
{
}
inline void afisare()
{
}
int main()
{
    citire();
    for( i = 1; i <= n; ++i)
    {
        for( j = 1; j <= m; ++j)
        {
            if(a[i] == b[j])
            {
                ma[i][j] = ma[i - 1][j - 1] + 1;
            }
            else
            {
                ma[i][j] = max(ma[i - 1][j], ma[i][j - 1]);
            }
        }
    }
    fout << ma[n][m];
    --i;--j;
    while(j)
    {
        if(a[i] == b[j])
        {
            solutie[nr++] = a[i];
            --j;
            --i;
        }
        else
        {
            if(ma[i - 1][j] > ma[i][j - 1])
            {
                --i;
            }
            else
            {
                --j;
            }
        }
    }
    fout << endl;
    for(int t = nr -1; t >= 0; --t)
    {
        fout << solutie[t] << " ";
    }
    return 0;
}
