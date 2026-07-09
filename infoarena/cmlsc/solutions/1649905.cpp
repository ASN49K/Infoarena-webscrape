#include<bits/stdc++.h>

using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");


const int NMax = 1024 + 1;
int L[NMax][NMax], x[NMax], y[NMax], n, m;

void citire()
{
        f>>n>>m;
        for(int i = 1; i <= n; i++)
            f>>x[i];
        for(int j = 1; j<= m; j++)
            f>>y[j];
}

void bordare()
{
        for(int i = 0; i <= n+1; i++)
            L[i][0] = 0;
        for(int j = 0; j <= m + 1; j ++)
            L[0][j] = 0;
}

void CMLSM()
{
    bordare();
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
    {
            if(x[i] == y[j])
                L[i][j] = L[i-1][j-1] +1;
            else
                if(x[i]  != y[j])
                    L[i][j] = max(L[i][j-1], L[i-1][j]) + 0;
    }
}

void afisare()
{
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++)
            g<<L[i][j]<<" ";
        g<<"\n";
    }

}


int main()
{
    citire();
    CMLSM();
    //afisare();
    g<<L[n][m]<<" \n";
    int i = n, j = m, k = 0;
    int s[NMax];
    while(i != 1 || j != 1)

        if(x[i] == y[j])
        {
            k++;
            s[k] = x[i];
            //g<<x[i]<<" ";
            if(i > 1)
                i--;
            if(j>1)
                j--;
        }
        else
            if(L[i-1][j] > L[i][j-1])
                i--;
            else
                j--;
    for(int i = k; i >= 1; i--)
        g<<s[i]<<" ";
}
