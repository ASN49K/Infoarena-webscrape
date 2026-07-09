///Recursiv
#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int m, n, s[1050][1050], a[1050], b[1050], v[1050];

void citire()
{
    fin>>m>>n;
    for(int i=1; i<=m; ++i)
        fin>>a[i];
    for(int i=1; i<=n; ++i)
        fin>>b[i];
    for(int i=1; i<=m; ++i)
        for(int j=1; j<=n; ++j)
        {
            if(a[i]==b[j]) s[i][j]=1+s[i-1][j-1];
            else s[i][j]=max(s[i-1][j], s[i][j-1]);
        }
}
int rezolvare(int i, int j)
{
    if(i<1 || j<1 || a[i]==0)
        return 0;
    if(a[i]==b[j])
    {
        rezolvare(i-1, j-1);
        fout<<a[i]<<" ";
    }
    else
    {
        if(s[i-1][j]>s[i][j-1])
            rezolvare(i-1, j);
        else
            rezolvare(i, j-1);
    }

}
/*void afisare()
{
    fout<<s[m][n]<<"\n";
    for(int i=1; i<=v[0]; i++)
        fout<<v[i]<<" ";
}*/
int main()
{
    citire();
    fout<<s[m][n]<<"\n";
    rezolvare(m, n);
    return 0;
}
