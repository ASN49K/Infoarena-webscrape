#include <bits/stdc++.h>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

const int NMAX = 1024;

int n, m;
int a[NMAX+1];
int b[NMAX+1];

int comun[NMAX+1][NMAX+1];

vector <int> ans;

int main()
{
    fin >> n >> m;
    for(int i=1; i<=n; i++)
        fin >> a[i];
    for(int j=1; j<=m; j++) 
        fin >> b[j];

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
            if(a[i] == b[j])
                comun[i][j] = 1;
    }
    int mini = 0, minj = 0;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            {
                if(comun[i][j] == 1 && i > mini && j > minj)
                    mini = i, minj = j, ans.push_back(a[i]);
            }
    for(int x : ans)
        fout << x << ' ';
    return 0;
}



/*
Aici crezusem ca trebuie sa gasim cel mai lung subsir crescator comun si am folosit o abordare destul de ineficienta.
Am format toate cele mai lungi subsiruri crescatoare cares e termina intr-un punct i si apoi am vazut partile comune ale celor doua siruri cu regex.
#include <bits/stdc++.h>
#include <regex>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
const int NMAX = 1024;

int n, m;
int a[NMAX+1];
int b[NMAX+1];
pair<int, string> dp[NMAX+1];
pair<int, string> dp2[NMAX+1];

int main() 
{
    fin >> n >> m;
    for(int i=1; i<=n; i++)
        fin >> a[i];
    for(int i=1; i<=m; i++)
        fin >> b[i];
    dp[1] = {1, to_string(a[1])+' '};
    dp2[1] = {1, to_string(b[1])+' '};
    for(int i=2; i<=n; i++) 
    {
        for(int j=1; j<i; j++) 
        {
            if(a[j] < a[i]) 
            {
                if(dp[j].first+1 > dp[i].first) {
                    dp[i].first = dp[j].first+1;
                    dp[i].second = dp[j].second+to_string(a[i])+' ';
                }
            }
        }
    }
    for(int i=2; i<=m; i++) 
    {
        for(int j=1; j<i; j++) 
        {
            if(b[j] < b[i]) 
            {
                if(dp2[j].first+1 > dp2[i].first) 
                {
                    dp2[i].first = dp2[j].first+1;
                    dp2[i].second = dp2[j].second+to_string(b[i])+' ';
                }
            }
        }
    }
    string maxi = " ";
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++) 
        {
            if(dp[i].second.size() > dp2[j].second.size())
            {
                regex r("(.*)"+dp2[j].second);
                if(regex_match(dp[i].second, r))
                {
                    if(dp2[j].second.size() > maxi.size())
                        maxi = dp2[j].second;
                }
            }
            else
            {
                regex r("(.*)"+dp[i].second);
                if(regex_match(dp2[j].second, r))
                {
                    if(dp[i].second.size() > maxi.size())
                        maxi = dp[i].second;
                }
            }
        }
    fout << maxi;
    return 0;
}*/ 
