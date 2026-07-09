#include <bits/stdc++.h>

using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int n, m, a[1050], b[1050], lcs[1050][1050];
vector<int> sol;

int main()
{
    fin >> n >> m;
    for(int i=1; i<=n; i++)
        fin >> a[i];
    for(int i=1; i<=m; i++)
        fin >> b[i];
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            if(a[i]==b[j])
                lcs[i][j]=1+lcs[i-1][j-1];
            else
                lcs[i][j]=max(lcs[i-1][j], lcs[i][j-1]);
    int i=n, j=m;
    while(i && j)
    {
        if(a[i]==b[j])
            sol.push_back(a[i]), i--, j--;
        else if(lcs[i-1][j]<lcs[i][j-1])
            j--;
        else
            i--;
    }
    fout << sol.size() << "\n";
    reverse(sol.begin(), sol.end());
    vector<int>::iterator it;
    for(it=sol.begin(); it!=sol.end(); it++)
        fout << *it << " ";
    return 0;
}
