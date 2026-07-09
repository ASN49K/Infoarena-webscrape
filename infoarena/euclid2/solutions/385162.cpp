#include <stdio.h>

using namespace std;

int main()
{
    FILE *fin,*fout;
    fin=fopen("euclid2.in","r");
    fout=fopen("euclid2.out","w");
    int t,a,b,r;
    fscanf(fin,"%d",&t);
    for (int i=1;i<=t;i++)
        {
            fscanf(fin,"%d %d",&a,&b);
            while (a%b!=0)
                {
                    r=a%b;
                    a=b;
                    b=r;
                }
            fprintf(fout,"%d\n",b);
            //fprintf(fout,/n);
        }
    fclose(fin);
    fclose(fout);
    return 0;
}
