#include <iostream>
#include <stdio.h>
#define max(x,y) ((x)>(y)?(x):(y))

using namespace std;

FILE *f1=freopen("cmlsc.in", "r", stdin);
FILE *f2=freopen("cmlsc.out", "w", stdout);
int n, m, a[1025], b[1025], l[1025][1025];
const int di[3]={-1, -1, 0}, dj[3]={0, -1, -1};

void cit()
{
    scanf("%d%d", &n, &m);
    for (int i=0; i<n; i++)
        scanf("%d", &a[i]);
    for (int j=0; j<m; j++)
        scanf("%d", &b[j]);
}

int lmax()
{
    for (int j=0; j<n; j++)
        if (a[j]==b[0])
            l[0][j]=1;
    for (int i=0; i<m; i++)
        if (a[0]==b[i])
            l[i][0]=1;
    for (int i=1; i<n; i++)
        for (int j=1; j<m; j++)
        {
            int maxi=0;
            for (int v=0; v<3; v++)
                maxi=max(maxi, l[i+di[v]][j+dj[v]]);
            l[i][j]=maxi;
            if (maxi==l[i-1][j-1] && a[i]==b[j])
                l[i][j]++;
        }
    return l[n-1][m-1];
}

void drum()
{
    int i=0, j=0;
    while (i!=n-1 || j!=m-1)
    {
        int maxi=0;
        if (l[i+1][j+1]>=l[i+1][j] && l[i+1][j+1]>=l[i][j+1])
        {
            if (a[i]==b[j])
            {
                printf("%d ", a[i]);
                i++;
                j++;
            }
        }
        if (l[i+1][j]>=l[i+1][j+1] && i+1<n && l[i+1][j]>=l[i][j+1] && j+1<m)
            j++;
        else
            i++;
    }
    if (a[i]==b[j])
        printf("%d ", a[i]);
}

void sol()
{
    printf("%d\n", lmax());
    drum();
}

int main()
{
    cit();
    sol();
    return 0;
}
