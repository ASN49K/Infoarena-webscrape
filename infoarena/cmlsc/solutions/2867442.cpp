#include <iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<fstream>
using namespace std;
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");
int n, m, cnt;
char a[1001], b[1001], rez[1001];
int d[1001][1001];

int main()
{   int n,m;
    in>>n>>m;
    in >> a >> b;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (a[i - 1] == b[j - 1])d[i][j] = d[i - 1][j - 1] + 1;
            else d[i][j] = max(d[i - 1][j], d[i][j - 1]);
    for (int i = n; i >= 1;) {
        for (int j = m; j >= 1;)
            if (a[i - 1] == b[j - 1]) rez[cnt++] = a[i - 1] ,i-- ,j--;
            else if (d[i - 1][j] < d[i][j - 1]) j--;
            else i--;
    } for (int i = cnt-1; i >=0; i--) out << rez[i];

}
