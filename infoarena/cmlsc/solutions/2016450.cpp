#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
#define FOR(i, a, b) for(i=a;i<=b;i++)
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
vector<int> sol;
int n, m, a[1024], b[1024], d[1024][1024];
int main()
{
    int i, j;
    f>>m>>n;
    FOR(i, 1, m)f>>a[i];
    FOR(i, 1, n)f>>b[i];
    FOR(i, 1, m)FOR(j, 1, n)
            if(a[i]==b[j])d[i][j]=1+d[i-1][j-1];
            else d[i][j]=max(d[i-1][j], d[i][j-1]);
    for(i=m, j=n;i;)
        if (a[i] == b[j])
            {
                sol.push_back(a[i--]);
                j--;
            }
        else if(d[i][j-1]>d[i-1][j])j--;
        else i--;

    g<<sol.size()<<'\n';
    for(i=sol.size()-1;i>=0;i--)
        g<<sol[i]<' ';
    return 0;
}
