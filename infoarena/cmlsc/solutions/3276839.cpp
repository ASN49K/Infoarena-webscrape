#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int dp[1025][1025];

int main()
{
    int n, m;
    fin>>n>>m;
    int a[n+1], b[m+1];
    for(int i=1; i<=n; i++)
    {
        fin>>a[i];
    }
    for(int i=1; i<=m; i++)
    {
        fin>>b[i];
    }
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(a[i]==b[j])
            {
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else
            {
                dp[i][j]=max(dp[i][j-1], dp[i-1][j]);
            }
        }
    }
    int MAX=dp[n][m], ii=n, jj=m;
    vector <int> subsir;
    //subsir.push_back(dp[ii][jj]) - adaug in vectorul "subsir" elementul dp[ii][jj]
    //subsir.pop() - scot ultimul element adaugat inb vectorul subsir
    while(ii>0 && jj>0)
    {
        if(a[ii]==b[jj])
        {
            subsir.push_back(a[ii]);
            ii--;
            jj--;
        }
        else
        {
            if(dp[ii-1][jj]>dp[ii][jj-1])
            {
                ii--;
            }
            else
            {
                jj--;
            }
        }
    }
    fout<<MAX<<endl;
    reverse(subsir.begin(), subsir.end());
    for(auto i : subsir)
    {
        fout<<i<<" ";
    }
    fin.close();
    fout.close();
    return 0;
}

/*
input:
5 3
1 7 3 9 8
7 5 8

output:
2
7 8

Cazul de baza - 
Recurenta - 
Structura de date folosita - 
*/