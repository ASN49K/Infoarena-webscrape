#include <stdio.h>


int x[1024][1024];
int m,n;
int a[1024],b[1024];
FILE *f;

void Olvas();
void Megold();
void Kiir();
void Nullaz();
void Vike(int, int);
int max(int, int);


int main()
{
    Olvas();

    Megold();

    Kiir();

    return 0;
}

void Olvas()
{
    f = fopen("cmlsc.in", "r");
    fscanf(f,"%d %d",&n,&m);
    for (int i=1;i<=n;i++)
        fscanf(f, "%d", &a[i]);
    for (int i=1;i<=m;i++)
        fscanf(f, "%d", &b[i]);
    fclose(f);
}

void Megold()
{
    Nullaz();
    for (int i = 1;i<=n;i++)
    {
        for (int j = 1;j<=m;j++)
        {
            if (a[i] == b[j])
            {
                x[i][j] = x[i-1][j-1] + 1;
            }
            else x[i][j] = max(x[i-1][j],x[i][j-1]);
        }
    }
}


void Nullaz()
{
    for (int i=0;i<=n;i++)
        x[i][0] = 0;
    for (int i=0;i<=m;i++)
        x[0][i] = 0;
}


void Kiir()
{
    f = fopen("cmlsc.out","w");
    fprintf(f, "%d\n", x[n][m]);

    Vike(n,m);

    fclose(f);
}


void Vike(int i, int j)
{
    if ((i==0) || (j==0)) return;
    if (a[i] == b[j])
    {
        Vike(i-1,j-1);
        fprintf(f,"%d ",a[i]);
    }
    else if (x[i-1][j] > x[i][j-1])
    {
        Vike(i-1,j);
    }
    else Vike(i,j-1);
}

int max(int a, int b)
{
    if (a > b)
        return a;
    return b;
}






