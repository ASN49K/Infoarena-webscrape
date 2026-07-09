#include <iostream>
#include <fstream>
#define NM 1040
#include <vector>
#define cout fout
using namespace std;
ifstream fin ("cmlsc.in");
ofstream fout ("cmlsc.out");
void read();
void rec(int i, int j);
vector<int> v;
int n, m, i, j;
int v1[NM], v2[NM], lcs[NM][NM], sir[NM];
int main()
{
    read();
    for(i=1; i<=n; i++)
        for(j=1; j<=m; j++)
        {
            if(v1[i] == v2[j])
                lcs[i][j] = 1 + lcs[i-1][j-1];
            else
                lcs[i][j] = max(lcs[i-1][j], lcs[i][j-1]);
        }
    cout << lcs[n][m] << '\n';
    rec(n, m);
    for(i=v.size()-1; i>=0; i--)
        cout << v[i] << ' ';

    return 0;
}

void rec(int i, int j)
{
    if(i==1 || j==1)
        v.push_back(v1[i]);
    else
    {
        if(lcs[i][j] > max(lcs[i-1][j], lcs[i][j-1]))
        {
            v.push_back(v1[i]);
            rec(i-1, j-1);
        }
        else if(lcs[i-1][j] >= lcs[i][j-1])
            rec(i-1, j);
        else rec(i, j-1);
    }
}

void read()
{
    fin >> n >> m;
    for(i=1; i<=n; i++)
        fin >> v1[i];
    for(j=1; j<=m; j++)
        fin >> v2[j];
}
