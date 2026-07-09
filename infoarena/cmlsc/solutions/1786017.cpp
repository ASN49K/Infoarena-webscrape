#include <cstdio>

using namespace std;
int a[1024], b[1024], m, n, com[1024], lm;
void citire(int a[1024], int &m, int b[1024], int &n)
{
    scanf("%d %d\n", &m, &n);
    for(int i=0; i<m; i++)
        scanf("%d ", &a[i]);
    for(int i=0; i<n; i++)
        scanf("%d ", &b[i]);
}
void lungime(int a[1024], int m, int b[1024], int n)
{
    int ui=0, uj=0;
    for(int i=0; i<m; i++)
        for(int j=0; j<n; j++)
        {
            if(a[i]==b[j]&&i>=ui&&j>=uj)
            {
                if(com[lm-1]!=a[i])
                com[lm++]=a[i];
                ui=i;
                uj=j;
            }
        }
    printf("%d\n%d ", lm, com[0]);
    for(int i=1; i<lm; i++)
            printf("%d ", com[i]);
}
int main()
{
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);
    citire(a, m, b, n);
    lungime(a, m, b, n);
    return 0;
}
