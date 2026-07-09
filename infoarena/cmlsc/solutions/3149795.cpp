#include <bits/stdc++.h>

using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
const int N=1030;
int n,m,a[N],b[N],d[N][N];
void afiseaza(int i,int j)
{
    if(d[i][j]==0)
        return;
    if(a[i]!=b[j])
    {
        if(d[i-1][j]>d[i][j-1])
            afiseaza(i-1,j);
        else
            afiseaza(i,j-1);
    }
    else
    {
        afiseaza(i-1,j-1);
        g<<a[i]<<' ';
    }
}
int main()
{
    f>>n>>m;
    for(int i=1; i<=n; i++)f>>a[i];
    for(int j=1; j<=m; j++)f>>b[j];
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
        {
            if(a[i]==b[j])
                d[i][j]=1+d[i-1][j-1];
            else
                d[i][j]=max(d[i-1][j],d[i][j-1]);
        }
    g<<d[n][m]<<'\n';
    return 0;
}
/// rezolvare: Metoda programarii dinamice
/// d[i][j] = care ar fi lungimea maxima a unui subsir comun daca as considera:
/// din primul sir doar prefixul pana la pozitia i
/// din al doilea sir doar prefixul pana la pozitia j
/// cum functioneaza:
/// am nevoie de o "formula de dinamica" care sa im calculeze d[i][j]
/// folosind rezultate deja calculate in pozitii <= i/j
/// cum functioneaza in acest caz:
/// daca a[i] == b[j] : d[i][j]=1+d[i-1][j-1]
/// daca a[i] != b[j] : d[i][j]=max(d[i-1][j],d[i][j-1])
/// in particular d[0][j]=d[i][0]=0->incep cu i=1 si j=1

