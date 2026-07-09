#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,a,b;
    FILE* pf=fopen("euclid2.in","r");
    if(pf==NULL)
    {
        printf("Nu s-a putut deschide fisierul ");
        exit(1);
    }
    FILE* pf1=fopen("euclid2.out","w");
    if(pf1==NULL)
    {
        printf("Nu s-a putut deschide fisierul in mod scriere ");
        exit(2);
    }

    fscanf(pf,"%d",&n);
    for(int i=0; i<n; i++)
    {
        fscanf(pf,"%d %d", &a, &b);
        if(a>b)
        {
            for(int j=b; j>0; j--)
                if((a%j==0)&&(b%j==0))
                {
                    fprintf(pf1,"%d\n",j);
                    break;
                }
        }
        else
        {
            for(int j=a; j>0; j--)
                if((a%j==0)&&(b%j==0))
                {
                    fprintf(pf1,"%d\n",j);
                    break;
                }
        }

    }
    fclose(pf);
    fclose(pf1);



    return 0;
}
