#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int v[1025][1025], t1[1025], t2[1025], n,m;

int main()
{
    freopen ("cmlsc.in", "r", stdin);
        scanf("%d %d", &n,&m);
        for (int i=1; i<=n; i++)
        {
            scanf("%d ", &t1[i]);
        }
        for (int i=1; i<=m; i++)
        {
            scanf("%d ", &t2[i]);
        }
    fclose(stdin);
        for (int i=1; i<=n; i++)
        {
            for (int j=1; j<=m; j++)
            {
                if (t1[i]==t2[j])
                {
                    v[i][j]=v[i-1][j-1]+1;
                }
                else if(v[i-1][j]>v[i][j-1])
                {
                    v[i][j]=v[i-1][j];
                }
                else v[i][j]=v[i][j-1];
            }
        }
    freopen ("cmlsc.out", "w", stdout);
        int max=v[n][m];
        for (int i=1; i<=n; i++)
        {
            for (int j=1; j<=n; j++)
            {
                if(max<v[i][j])
                    max=v[i][j];
            }
        }
        vector <int> v2;
        printf("%d\n", max);
        while(n>0 && m>0)
        {
            if (t1[n]==t2[m])
            {
                v2.push_back(t1[n]);
                n--;
                m--;
            }
            else if (v[n-1][m]>v[n][m-1])
            {
                n--;
            }
                else m--;
        }
    for (int i=v2.size()-1; i>=0; i--)
           printf("%d ", v2.at(i));
    fclose(stdout);
    return 0;
}
