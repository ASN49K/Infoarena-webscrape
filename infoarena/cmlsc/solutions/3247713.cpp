#include <bits/stdc++.h>
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int n , m;
int a[1030] , b[1030];

int main()
{
    int i , j;
    fin >> n >> m;
    for(i = 1;i <= n;i++)
        fin >> a[i];
    for(j = 1;j <= m;j++)
        fin >> b[j];
    for(i = 1;i <= n;i++)
    {
        for(j = 1;j <= m;j++)
            if(a[i] == b[j]) fout << a[i] << " ";
    }
    return 0;
}
/**

*/
