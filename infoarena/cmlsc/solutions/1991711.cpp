#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <stack>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

const int N = 1034;

int n, m;
int x[N], y[N];
int a[N][N];
int i, j;
int ossz;
stack <int> er;

int main()
{
    fin >> n >> m;

    for(i = 1; i <= n; ++i)
        fin >> x[i];

    for(i = 1; i <= m; ++i)
        fin >> y[i];

    for(i = 1; i <= n; ++i)
    {
        for(j = 1; j <= m; ++j)
        {
            if(x[i] == y[j])
                a[i][j] = a[i-1][j-1] + 1;
            else
                a[i][j] = max(a[i-1][j], a[i][j-1]);

//            cout << a[i][j] << " ";
        }
//        cout << "\n";
    }

    ossz = a[n][m];
    i = n;
    j = m;
    fout << ossz << "\n";

    while(a[i][j] != 0)
    {
//        cout << "!";
        while(a[i-1][j] == ossz)
            --i;
        while(a[i][j-1] == ossz)
            --j;

        er.push(x[i]);
        --ossz;
        --i;
        --j;
    }

    while(er.size())
    {
        fout << er.top() << " ";
        er.pop();
    }

    return 0;
}
