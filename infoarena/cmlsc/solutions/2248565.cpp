#include <iostream>
#include <fstream>
#include <vector>
#define cout fout
using namespace std;
ifstream fin ("cmlsc.in");
ofstream fout ("cmlsc.out");
void read();
vector<int> v;
int n, m, i, j;
int v1[1027], v2[1027], lcs[1030][1030];
int main()
{
    read();
    for(i=1; i<=n; i++)
        for(j=1; j<=m; j++)
        {
            if(v1[i] == v2[j])
            {
                lcs[i][j] = 1 + lcs[i-1][j-1];
                v.push_back(v1[i]);
            }
            else
                lcs[i][j] = max(lcs[i-1][j], lcs[i][j-1]);
        }
    cout << lcs[n][m] << '\n';
    for(i=0; i<v.size(); i++)
        cout << v[i] << ' ';

    return 0;
}

void read()
{
    fin >> n >> m;
    for(i=1; i<=n; i++)
        fin >> v1[i];
    for(j=1; j<=m; j++)
        fin >> v2[j];
}
