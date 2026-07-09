#include<cstdio>
#include<algorithm>
using namespace std;
FILE*in=fopen("cmlsc","r");
FILE*out=fopen("cmlsc","w");
int A,B,i,j, m[1027][1027], v1[1027],v2[1027], vaux[1027], ct = 1;
int main()
{
    fscanf(in,"%d%d",&A,&B);
    for(i=1; i<=A; i++)
    {
        fscanf(in,"%d",&v1[i]);
    }
    for(j=1; j<=B; j++)
    {
        fscanf(in,"%d",&v2[j]);
    }
    /*for(i=1; i<=A; i++)
    {
        for(j=1; j<=B; j++)
        {
            if(v1[i]==v1[j])
            {
                m[i][j]=m[i-1][j-1]+1;
            }
            else
            {
                m[i][j]=max(m[i-1][j],m[i][j-1]);
            }
        }
    }
    fprintf(out,"%d\n",m[A][B]);*/
    /*i=A;
    j=B;
    while(i!=0&&j!=0)
    {
        if(v1[i]==v2[j])
        {
            vaux[ct] = v1[i];
            ++ct;
        }

        if(m[i-1][j-1]==m[i][j]-1)
        {
            i--;
            --j;
        }
        if(m[i-1][j] < m[i][j - 1]) --j;
        else --i;
    }
    --ct;
    for(int r = ct; r >= 1; ++r)
    {
        fprintf(out,"%d",vaux[r]);
    }*/
}


