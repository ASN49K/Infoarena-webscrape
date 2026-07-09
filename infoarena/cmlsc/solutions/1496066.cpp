#include <iostream>
#include <cstdio>

using namespace std;

int A[1100],B[1100],n,m,C[1100][1100],rasp[1050],bst;


void read()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);

    scanf("%d%d",&n,&m);

    for (int i=1;i<=n;++i)
        scanf("%d",&A[i]);


    for (int i=1;i<=m;++i)
        scanf("%d",&B[i]);
}


int main()
{
    read();

    for (int i=1;i<=n;++i)
        for (int j=1;j<=m;++j)
            if (A[i]==B[j])
               C[i][j]=1+C[i-1][j-1];

            else
                C[i][j]=max(C[i-1][j],C[i][j-1]);

    for (int i=n,j=m;i;)
        if (A[i]==B[j])
        {
            rasp[++bst]=A[i]; ///daca sunt egale, bag in vector
            --i;               ///ma misc inapoi in vector A si B
            --j;
        }
        else if (C[i-1][j]>C[i][j-1]) ///inseamna ca nr A[i] este egal cu un B[j'] (j'<j) care face subsecventa maxima
            --i;
        else --j; ///inseamna ca nr B[j] este egal cu un A[i'](i'<i) cu care face subsecventa maxima

    printf("%d\n",bst);

    for (int i=bst;i;--i)
        printf("%d ",rasp[i]);

    return 0;
}
