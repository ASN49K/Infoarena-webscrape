#include <bits/stdc++.h>
//#define us unsigned short
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int sir1[1026], sir2[1026], tab[1027][1027], n, m, x, i, j;

int main()
{
    fin >> n >> m;
    for(i = 1; i <= n; i++)
        fin >> sir1[i];
    for(j = 1; j <= m; j++)
        fin >> sir2[j];
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= m; j++)
        {
            if(sir1[i] == sir2[j])
                tab[i][j] = tab[i-1][j] + 1;
            else tab[i][j] = max(tab[i-1][j], tab[i][j-1]);
        }
    }
    i = n, j = m;
    stack <int> st;
    while(tab[i][j])
    {
        while(tab[i][j] == tab[i-1][j])
            i--;
        while(tab[i][j] == tab[i][j-1])
            j--;
        st.push(sir1[i]), --i, ++x;
    }
    fout << x << '\n';
    while (!st.empty())
    {
        fout << st.top() << ' ';
        st.pop();
    }
}
