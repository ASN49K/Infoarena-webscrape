#include  <iostream>
#include  <fstream>
#include  <stack>
#define   Nmax 1030

using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int n, m;
int a[Nmax], b[Nmax];
int cmlsc[Nmax][Nmax]; // cmlsc[i][j] - lungimea celui mai lung subsir comun a a[1...i], b[1...j]
stack <int> st;

int main()
{
    f >> n >> m;
    for (int i = 1; i <= n; i++) f >> a[i];
    for (int j = 1; j <= m; j++) f >> b[j];

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (a[i] == b[j]) cmlsc[i][j]=cmlsc[i-1][j-1]+1;
            else cmlsc[i][j]=max(cmlsc[i-1][j], cmlsc[i][j-1]);

    int i = n, j = m;

    while (cmlsc[i][j]!=0)
    {
        while (cmlsc[i][j] == cmlsc[i-1][j]) i--;
        while (cmlsc[i][j] == cmlsc[i][j-1]) j--;
        st.push(a[i]);
        i--, j--;
    }
    while (!st.empty())
    {
        g << st.top() << " ";
        st.pop();
    }

    return 0;
}
