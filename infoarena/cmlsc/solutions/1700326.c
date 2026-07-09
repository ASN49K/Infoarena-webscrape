#include <stdio.h>
unsigned char a[1024],b[1024];
short int matrix[1025][1025],sir[1025];
inline int maxim(short a,short b)
{
    if(a>b)
        return a;
    return b;
}
int main()
{
    FILE *fin,*fout;
    fin=fopen("cmlsc.in","r");
    fout=fopen("cmlsc.out","w");
    int n,i,j,m,lung;
    fscanf(fin,"%d%d",&m,&n);
    for(i=1;i<=m;i++)
        fscanf(fin,"%d",&a[i]);
    for(i=1;i<=n;i++)
        fscanf(fin,"%d",&b[i]);
    for(i=1;i<=m;i++)
        for(j=1;j<=n;j++)
        {
            if(a[i]==b[j])
                matrix[i][j]=1+matrix[i-1][j-1];
            else
                matrix[i][j]=maxim(matrix[i][j-1],matrix[i-1][j]);
        }
    lung=0;
    i=m;j=n;
    while(i && j)
    {
        if(a[i]==b[j])
        {
            sir[lung]=a[i];
            lung++;
            i--;j--;
        }
        else
            if(matrix[i][j-1]>matrix[i-1][j])
                j--;
        else
            i--;
    }
    fprintf(fout,"%d\n",lung);
    for(i=lung-1;i>=0;i--)
        fprintf(fout,"%hd ",sir[i]);
    fclose(fin);
    fclose(fout);
    return 0;
}
