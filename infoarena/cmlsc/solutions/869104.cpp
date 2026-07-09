//Include
#include <stdio.h>

//Definitii
#define max(a, b) (a>b) ? a : b

//Constante
const int sz=1025;

//Functii
FILE *in, *out;

int length1, length2, string1[sz], string2[sz],common[sz],matrix[sz][sz], answer;
int i,j;

int main()
{
    in=fopen("cmlsc.in","rt");
    out=fopen("cmlsc.out","wt");
    fscanf(in,"%d%d",&length1, &length2);

    for(i=1;i<=length1;++i)
        fscanf(in,"%d",&string1[i]);
    for(i=1;i<=length2;++i)
        fscanf(in,"%d",&string2[i]);

    for(i=1;i<=length1;++i)
        for(j=1;j<=length2;++j)
            if(string1[i]==string2[j])
                matrix[i][j]=1+matrix[i-1][j-1];
            else
                matrix[i][j]=max(matrix[i-1][j], matrix[i][j-1]);

    for( i=length1 , j=length2 ; i ; )
    {
        if(string1[i]==string2[j])
        {
            common[++answer]=string1[i];
            i--;
            j--;
        }
        else if(matrix[i-1][j] < matrix[i][j-1])
            j--;
        else i--;
    }

    fprintf(out,"%d\n",answer);
    for( i=answer ; i>=1 ; --i)
        fprintf(out,"%d ",common[i]);


    fclose(in);
    fclose(out);
    return 0;
}

