#include <iostream>
#include <fstream>
#include <stack>
using namespace std;
int max(int a, int b)
{
    return (a > b ? a : b);
}

int main()
{
    int n, m; //lungimea lui A respectiv B

    ifstream f("cmlsc.in");
    ofstream g("cmlsc.out");

    f >> n >> m;
    int A[n+3], B[n+3], a[n+3][m+3];     // +constanta sa fim siguri ca nu avem probleme

    a[0][0] = 0;
    for(int i=1; i<=n; i++)     //citim A -vectoru1
    {
        f >> A[i];
        a[i][0] = 0;
    }
    for(int i=1; i<=m; i++)     //citim B - vectoru2
    {
        f >> B[i];
        a[0][i] = 0;
    }

    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            if(A[i]==B[j]) a[i][j] = a[i-1][j-1] + 1;   // daca A[i]==B[j] putem fi siguri atunci ca perechea asta va aduce un plus la toate sirurile comune existente
                      else a[i][j] = max(a[i][j-1], a[i-1][j]); // daca nu, perechea asta nu aduce nimic in plus, doar retine ce am obtinut anterior

    int k= a[n][m]; // lungimea sirului comun maximal
    stack<int> stk;   // mergem in sens invers
    g << k << "\n";
    while(k!=0)
    {
        while(a[n-1][m-1] == k){n--; m--;};
        while(a[n-1][m] == k) n--;
        while(a[n][m-1] == k) m--;
        stk.push(A[n]);  //sau B[m], fiind identice in momentul asta
        k--;
    }

    while (!stk.empty())
    {
        g << stk.top() << " ";
             stk.pop();
    }

    f.close();
    g.close();

    return 0;
}
