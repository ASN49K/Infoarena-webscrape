#include <bits/stdc++.h>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

const int CMAX = 1030;
int n , m , pd[CMAX][CMAX] , v1[CMAX] , v2[CMAX] , i , j , rasp[CMAX] , r;

void citire()
{
    fin >> n >> m;
    for(i=1;i<=n;i++)
        fin >> v1[i];
    for(j=1;j<=m;j++)
        fin >> v2[j];
}

void afisare()
{
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            cout << pd[i][j] << " ";
        }
        cout << '\n';
    }
}

int main()
{
    citire();
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            if(v1[i]==v2[j])
            {
                pd[i][j] = pd[i-1][j-1] + 1;
            }
            else pd[i][j] = max(pd[i-1][j],pd[i][j-1]);
        }
    }
    i = n;
    j = m;
    r = 1;
    while(i!=0&&j!=0)
    {
        if(v1[i]==v2[j])
        {
            rasp[r++] = v1[i];
            i--;
            j--;
        }
        else
        {
            if(pd[i][j]==pd[i-1][j])
                i--;
            else
                j--;
        }
    }
    fout << pd[n][m] << '\n';
    r--;
    for(r;r>=1;r--)
        fout << rasp[r] << " ";
    return 0;
}
