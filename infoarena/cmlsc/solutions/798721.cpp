#include<fstream>

using namespace std;
int  n, m, a[10000], b[10000], l[10000][10000], s[10000];
ifstream f ("cmlsc.in");
FILE *g = fopen("cmlsc.out", "w");

int max(int a, int b)
{
    if(a>b)
        return a;
    else
        return b;
}

int main()
{
int i, j, cont;

cont=1;
f>>n>>m;

for(i=1; i<=n; i++)
    f>>a[i];

for(i=1; i<=m; i++)
    f>>b[i];

for(i=n; i>=1; i--)
    for(j=m; j>=1; j--)
        {
                if(a[i]==b[j])
                    {
                    l[i][j]=1+l[i+1][j+1];
                    }
                else
                    l[i][j]=max(l[i+1][j], l[i][j+1]);
        }


fprintf(g, "%d\n", l[1][1]);
i=1;
j=1;
while(i<=n && j<=m)
{
    if(a[i]==b[j])
        {
        s[cont++]=a[i];
        i++;
        j++;
        }
    else
        if(l[i+1][j]>l[i][j+1])
            i++;
        else
            j++;
}

for(i=1; i<=l[1][1]; i++)
    fprintf(g, "%d ", s[i]);

f.close();
fclose(g);
return 0;
}
