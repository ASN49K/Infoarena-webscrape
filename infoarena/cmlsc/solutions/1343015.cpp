#include <stdio.h>
#define N_MAX (1024)

#define max(a,b) (a>b?a:b)


int cmlsc[N_MAX+1][N_MAX+1];

int X[N_MAX],Y[N_MAX],secv[N_MAX];

int main()
{
    FILE *fin=fopen("cmlsc.in","r"),
         *fout=fopen("cmlsc.out","w");
    int m,n;
    int i,j;
    int k;


    fscanf(fin,"%d %d",&m,&n);

    for(i=0;i<m;i++)
        fscanf(fin,"%d ",&X[i]);
    for(j=0;j<n;j++)
        fscanf(fin,"%d ",&Y[j]);

    for(i=1;i<m;i++)//O(n^2)
    {
        for(j=1;j<n;j++)
        {
            if(X[i-1]==Y[j-1])
            {
                cmlsc[i][j]=cmlsc[i-1][j-1]+1;
            }
            else
            {
                cmlsc[i][j]=max(cmlsc[i-1][j],cmlsc[i][j-1]);
            }
        }
    }

    i=m;
    j=n;
    k=0;
    while(i!=0)//O(n)--marime maxima N_MAX
    {
        if(X[i-1]==Y[j-1])
            secv[k++]=X[i-1],i--,j--;
        else
            if(cmlsc[i-1][j]<cmlsc[i][j-1])
                j--;
            else i--;
    }

    fprintf(fout,"%d\n",k);

    for(i=k-1;i>-1;i--)
        fprintf(fout,"%d ",secv[i]);

    fclose(fin);
    fclose(fout);
    return 0;
}
