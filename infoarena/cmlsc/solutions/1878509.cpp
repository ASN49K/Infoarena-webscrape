#include <bits/stdc++.h>
#define nmax 1030

using namespace std;

int u[nmax];
int v[nmax];
int n, m;

int dinamica[nmax][nmax];

void lcs()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(u[i]==v[j])
                dinamica[i][j]=dinamica[i-1][j-1]+1;
            else
                dinamica[i][j]=max(dinamica[i-1][j], dinamica[i][j-1]);
        }
    }
}


int main()
{
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);

    scanf("%d%d", &n, &m);
    for(int i=1;i<=n;i++)
        scanf("%d", &u[i]);
    for(int j=1;j<=m;j++)
        scanf("%d", &v[j]);
    lcs();
    printf("%d\n", dinamica[n][m]);

    int last_1, last_2;
    last_1=n;
    last_2=m;
    int current=dinamica[last_1][last_2];
    bool transf=true;
    stack <int> raspuns;
    while(last_1&&last_2&&current!=0)
    {
        transf=false;
        if(dinamica[last_1-1][last_2]==current)
        {
            transf=true;
            last_1--;
        }else if(dinamica[last_1][last_2-1]==current)
        {
            transf=true;
            last_2--;
        }
        if(transf==false)
        {
            transf=true;
            raspuns.push(v[last_2]);
            last_1--;
            current=dinamica[last_1][last_2];
        }
    }
    while(!raspuns.empty())
    {
        printf("%d ", raspuns.top());
        raspuns.pop();
    }
    printf("\n");

    return 0;
}
