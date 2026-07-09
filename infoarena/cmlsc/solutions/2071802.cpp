#include <stdio.h>
#include <stdlib.h>
using namespace std;


void citire(int *** mat, int ** sirA, int ** sirB,int *m,int *n)
{

    FILE * fin = fopen("cmlsc.in","r");
    fscanf(fin,"%d %d",m,n);
    (*sirA) = (int *) malloc(((*m)+2)*sizeof(int));
    (*sirB) = (int *) malloc(((*n)+2)*sizeof(int));

    *mat = (int **)malloc(((*m)+1)*sizeof(int*));
    for(int i=0;i<=((*m));i++)
    {
        (*mat)[i]=(int *)calloc(((*n)+1),sizeof(int));
    }

    for(int i=1;i<=*m;i++)
    {
        fscanf(fin,"%d",(*sirA)+i);
    }

    for(int i=1;i<=*n;i++)
    {
       fscanf(fin,"%d",(*sirB)+i);
    }
}

int maxim(int a, int b)
{
    if(a>b)
        return a;
    return b;
}

void cmlsc(int m, int n, int * sirA, int * sirB, int *** mat, FILE * fout)
{
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++)
            if(sirA[i]==sirB[j])
                (*mat)[i][j]=(*mat)[i-1][j-1]+1;
            else
                (*mat)[i][j]=maxim((*mat)[i-1][j],(*mat)[i][j-1]);

    fprintf(fout,"%d\n",(*mat)[m][n]);
}

void path(int m, int n, int * sirA, int * sirB, int ** mat, FILE * fout)
{
    int k=0,i=m;
    int* sol = (int *)malloc((mat[m][n])*sizeof(int));
    for(int j=n;j>0;)
            if(sirA[i]==sirB[j])
            {
                sol[k++]=sirA[i];
                j--;
                i=m;
            }
            else
            {
                if(i!=0)
                    i--;
                else
                {
                    j--;
                    i=n;

                }
            }
    for(int i=mat[m][n]-1;i>=0;i--)
        fprintf(fout,"%d ",sol[i]);

}

int main()
{
    int ** mat;
    int * sirA;
    int *sirB;
    int m,n;
    citire(&mat,&sirA,&sirB,&m,&n);
    FILE * fout = fopen("cmlsc.out","w");
    cmlsc(m,n,sirA,sirB,&mat,fout);
    path(m,n,sirA,sirB,mat,fout);




    return 0;
}
