#include<cstdio>
#include<cstdlib>
#define Nmax 1024
#define maxim(a, b) (a>b) ? a:b

int m, n, a[Nmax], b[Nmax], C[Nmax][Nmax];

typedef struct solutie
{
    int n; //numarul de cifre
    int *sir; //cel mai lung subsir comun
};

void citeste()
{
    //fisierul de intrare
    freopen("cmlsc.in", "r", stdin);

    scanf("%d %d", &m, &n);
    for(int i=0; i<m; i++)
        scanf("%d", &a[i]);
    for(int i=0; i<n; i++)
        scanf("%d", &b[i]);
}

solutie progr_dinamica()
{
    int i, j; solutie x, y;

    //aloc memorie pt. sirul solutie
    x.sir=(int*)malloc(maxim(m,n)*sizeof(int));

    y.sir=x.sir; //retin inceputul sirului
    x.n=0;
    for(i=0; i<m; i++)
        for(j=0; j<n; j++)
            if(a[i]==b[j])  //daca face parte din subsir
            {
                //adaug la solutie
                *(x.sir)=a[i], (x.sir)++;
                x.n++;

                C[i+1][j+1]=C[i][j]+1;
            }
            else
                C[i+1][j+1]=maxim(C[i+1][j], C[i][j+1]);

    //eliberez blocul de memorie nefolosit
    //de la x.sir la maxim(m,n)
    free(x.sir);

    y.n=x.n;
    return y;
}


void scrie()
{
    //fisierul de iesire
    freopen("cmlsc.out", "w", stdout);

    solutie s=progr_dinamica();
    printf("%d\n", s.n);
    for(int i=0; i<s.n; i++)
        printf("%d ", *((s.sir)+i));
}


int main()
{
    citeste();
    scrie();
    return 0;
}
