#include <iostream>
#include <fstream>
#include <stack>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int n,m,x[1050],y[1050],z[1050][1050];
stack <int> stiva;
void citire()
{
    fin>>n>>m;
    int i;
    for(i=1; i<=n; i++)
        fin>>x[i];
    for(i=1; i<=m; i++)
        fin>>y[i];
}
void prelucrare()
{
    int i,j;
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=m; j++)
        {
            if(x[i]==y[j])
                z[i][j]=z[i-1][j-1]+1;
            else
                z[i][j]=max(z[i-1][j],z[i][j-1]);
        }
    }
}
void afisare()
{
    int i,j;
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=m; j++)
            cout << z[i][j] << " ";
        cout << "\n";
    }
}
void raspuns()
{
    fout << z[n][m] << "\n";
    int i=n,j=m;

    while(x[i] && y[j])
    {
        while(z[i][j]==z[i-1][j])
            i--;
        while(z[i][j]==z[i][j-1])
            j--;
        if(x[i] && y[j])
            stiva.push(x[i]);
        i--;j--;
    }

    while(!stiva.empty())
    {
        fout << stiva.top()<< " ";
        stiva.pop();
    }
}
int32_t main()
{
    citire();
    prelucrare();
    raspuns();
    return 0;
}
