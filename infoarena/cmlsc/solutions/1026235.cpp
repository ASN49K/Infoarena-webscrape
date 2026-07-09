#include <stdio.h>
using namespace std;
int vect[1001],h,ap[1000005],aux[1000005],vect2[1001],h2,h3=0,h4=0;
int main()
{
    FILE *fin = fopen("cmlsc.in", "r");
    FILE *fout = fopen("cmlsc.out", "w");

    int n,i,j,k;
    int x;
    fscanf(fin,"%d",&n);   fscanf(fin,"%d",&k);
    for(j=1;j<=k;j++)
    {   h++;
        fscanf(fin,"%d",&vect[h]);
        ap[vect[h]]++;
        h3++;}
    for(i=2;i<=n;i++)
    {   fscanf(fin,"%d",&k);
        h2=0;
        h4=0;
        for(j=1;j<=k;j++)
        {   fscanf(fin,"%d",&x);
            if(ap[x]>0)
            {   if(aux[x]==0)
                {   h2++;
                    vect2[h2]=x;
                    aux[x]++;}
                else if(aux[x]<ap[x]) aux[x]++;}}
            for(j=1;j<=h;j++) ap[vect[j]]=0;
            for(j=1;j<=h2;j++)
            {   vect[j]=vect2[j];
                ap[vect2[j]]=aux[vect2[j]];
                h4+=ap[vect2[j]];}
            for(j=1;j<=h2;j++) aux[vect2[j]]=0;
            h=h2;
            h3=h4;
    }
    fprintf(fout,"%d",h3);
    //char c=32+'0';
    fprintf(fout,"\n");
    for(i=1;i<=h;i++)
    {   for(j=1;j<=ap[vect[i]];j++)
        {   fprintf(fout,"%d",vect[i]);
            fprintf(fout," ");
        }
    }
    fclose(fin);
    fclose(fout);

    return 0;
}