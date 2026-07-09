#include <bits/stdc++.h>

using namespace std;
int sir1[1050],sir2[1050],n,m,sol[1050][1050];

ofstream fout("cmlsc.out");

void Solutie()
{
    int i,j;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            if(sir1[i]==sir2[j]) sol[i][j]=sol[i-1][j-1]+1;
            else
            {
                if(sol[i-1][j]>=sol[i][j-1]) sol[i][j]=sol[i-1][j];
                else sol[i][j]=sol[i][j-1];
            }
        }
    }
}

void Afisare()
{
    int i,j;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
            cout<<sol[i][j]<<" ";
        cout<<"\n";
    }
}

void AfisareSol(int i, int j)
{
    if(sol[i][j]!=0)
    {
        if(sir1[i]==sir2[j])
        {
            AfisareSol(i-1,j-1);
            fout<<sir1[i]<<" ";
        }
        else
        {
            if(sol[i-1][j]>=sol[i][j-1]) AfisareSol(i-1,j);
            else AfisareSol(i,j-1);
        }
    }
}

int main()
{
    int i;
    ifstream fin("cmlsc.in");
    fin>>n>>m;
    for(i=1;i<=n;i++)
        fin>>sir1[i];
    for(i=1;i<=m;i++)
        fin>>sir2[i];
    fin.close();
    Solutie();
    fout<<sol[n][m]<<"\n";
    AfisareSol(n,m);


    fout.close();
    //Afisare();
    return 0;
}
