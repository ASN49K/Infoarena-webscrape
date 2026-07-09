#include <bits/stdc++.h>
using namespace std;
//Fie v un vector cu N elemente. Se numeste subsir de lungime K al vectorului v un nou vector v' = (vi1, vi2, ... viK), cu i1 < i2 < ... < iK.
//De exemplu, vectorul v = (5 7 8 9 1 6) contine ca subsir sirurile (5 8 6) sau (7 8 1), dar nu contine subsirul (1 5).
//Se dau doi vectori A si B cu elemente numere naturale nenule.
//Sa se determine subsirul de lungime maxima care apare atat in A cat si in B.

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

const int N = 1030;
int a[N],b[N],lcs[N][N];
int main()
{
    int na,nb;
    in>>na>>nb;
    for(int i=1;i<=na;i++)
        in>>a[i];
    for(int i=1;i<=nb;i++)
        in>>b[i];
    //lcs = longest common subsequence
    //fie a de i subsirul format din primele i el. ale lui a
    //lcs(a de i, b de j) - numarul de el din lcs-ul dintre primele i el. ale lui a
    //si primele j el. ale lui b
    //lcs[na][nb] - numarul de el. din lcs-ul dintre a si b

    for(int i=1;i<=na;i++)
        for(int j=1;j<=nb;j++)
        if(a[i]==b[j]) lcs[i][j]=lcs[i-1][j-1]+1;
    else lcs[i][j]=max(lcs[i-1][j],lcs[i][j-1]);

    vector <int> sol;
    int i=na,j=nb;

    while(i && j)
    {
        if(a[i]==b[j])
        {
            sol.push_back(a[i]);
            i--;j--;
        }
        else if(lcs[i][j-1]>lcs[i-1][j]) j--;
        else i--;

    }

    out<<lcs[na][nb]<<'\n';
    for(int i=sol.size()-1;i>=0;i--)
        out<<sol[i]<<' ';
    return 0;
}
