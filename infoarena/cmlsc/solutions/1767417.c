#include<stdio.h>
#define NMAX 1024
unsigned int  a[NMAX],b[NMAX], m ,n,d[NMAX][NMAX], subsequence[NMAX];
int main()
{
    FILE *f, *g;


    int i=0,j=0, longest_subsequence=0,k=0;

    f=fopen("cmlsc.in","r");
    g=fopen("cmlsc.out","w");

    fscanf(f,"%u",&n);
    fscanf(f,"%u",&m);


    for(i=1;i<=n;i++)
        fscanf(f,"%u",&b[i]);
    for(j=1;j<=m;j++)
        fscanf(f,"%u",&a[j]);
    for(j=0;j<=m;j++) d[0][j]=0;
    for(i=0;i<=n;i++) d[i][0]=0;

    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            if(b[i]==a[j])
                d[i][j]=d[i-1][j-1]+1;
            else{
                    if(d[i][j-1]>d[i-1][j])
                        d[i][j]=d[i][j-1];
                    else
                        d[i][j]=d[i-1][j];
                }

    longest_subsequence = d[n][m];
     i=n;
     j=m;
      k=longest_subsequence;
     while(k>=1){

        if(d[i][j-1]==k) j--;
        else if(d[i-1][j]==k) i--;
        else {
                subsequence[k]=a[j];k--;
               i--;j--;
             }
     }

     fprintf(g,"%u\n",longest_subsequence);
     for(i=1;i<=longest_subsequence;i++)
        fprintf(g,"%u ",subsequence[i]);


}
