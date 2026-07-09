#include <cstdio>

using namespace std;

int m,n,k=0;
int A[1024],B[1024],best[1024];

void Read()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    scanf("%i %i",&m,&n);
    for(int i=0;i<m;i++)
        scanf("%i",&A[i]);
    for(int i=0;i<n;i++)
        scanf("%i",&B[i]);
}

void Dinamic(int a ,int b ,int Z[] ,int Y[])
{
    for(int i=0;i<a;i++)
    {
        for(int j=0;j<b;j++)
        {
            if(Z[i] == Y[j])
            {
                best[k] = Y[j];
                k++;
            }
        }
    }
}

int main()
{
    Read();
    if(m > n)
        Dinamic(m , n , A , B);
    else
        Dinamic(n , m , B , A);
    printf("%i\n",k);
    for(int i=0;i<k;i++)
        printf("%i ",best[i]);
    return 0;
}
