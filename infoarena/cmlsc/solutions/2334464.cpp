#include <bits/stdc++.h>
using namespace std;
ifstream fin ("cmlsc.in");
ofstream fout ("cmlsc.out");
int A [1033], B [1033], dp [1033][1033], Ans [1033];
int cnt, n, m, I, J;
int main (){
    fin >> n >> m;
    for (int i = 1; i <= n; i ++)
        fin >> A [i];
    for (int i = 1; i <= m; i ++)
        fin >> B [i];
    for (int i = 1; i <= n; i ++){
        for (int j = 1; j <= m; j ++){
            if (A [i] == B [j])dp [i][j] = dp [i - 1][j - 1] + 1;
            else dp [i][j] = max (dp [i - 1][j], dp [i][j - 1]);
        }
    }
    I = n, J = m;
    cnt = dp [n][m];
    while (I && J){
        if (A [I] == B [J])
            Ans [cnt --] = A [I], I --, J --;
        else if (dp [I][J - 1] > dp [I - 1][J])J --;
        else I --;
    }cnt = dp [n][m];
    fout << cnt << '\n';
    for (int i = 1; i <= cnt; i ++)
        fout << Ans [i] << " ";
    return 0;
}
