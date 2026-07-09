#include <bits/stdc++.h>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

stack <int> vect;
int sir[1025][1025];

int main(){
    int i, j, n, m, M[1025], N[1025], numar;
    fin >> n >> m;

    // N[]
    for(i=1;i<=n;i++)
        fin >> N[i];

    // M[]
    for(i=1;i<=m;i++)
        fin >> M[i];

    for(i=1;i<n;i++)
        if(N[i] == M[1])
            while(i<=n)
                sir[i][1]=1, i++;

    for(i=1;i<m;i++)
        if(N[1] == M[i])
            while(i<=m)
                sir[1][i]=1, i++;

    for(i=2;i<=n;i++)
        for(j=2;j<=m;j++)
            if(N[i] == M[j])
                sir[i][j] = sir[i-1][j-1] + 1;
            else
                sir[i][j] = max(sir[i-1][j], sir[i][j-1]);

    fout << sir[n][m] << "\n";
    numar = sir[n][m];

    for(i=n;i>=1;i--)
        for(j=m;j>=1;j--)
            if(N[i] == M[j] && sir[i][j] == numar)
                vect.push(N[i]), i--, numar--;

    while(vect.empty() == 0)
        fout << vect.top() << " ", vect.pop();

    return 0;
}