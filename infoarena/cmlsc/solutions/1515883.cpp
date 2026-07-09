#include <cstdio>
using namespace std;
FILE *in,*out;
short int m[1025][1025],v[1025],w[1025],s[1025];
int main()
{
    in=fopen("cmlsc.in","r");
    out=fopen("cmlsc.out","w");
    short int lv,lw,i,j,k=0;
    fscanf(in,"%hd%hd",&lv,&lw);
    for(i=1;i<=lv;++i)fscanf(in,"%hd",&v[i]);
    for(i=1;i<=lw;++i)fscanf(in,"%hd",&w[i]);
    for(i=1;i<=lv;++i)for(j=1;j<=lw;++j)
    {
        if(v[i]==w[j])m[i][j]=m[i-1][j-1]+1;
        else
        {
            if(m[i-1][j]>m[i][j-1])m[i][j]=m[i-1][j];
            else m[i][j]=m[i][j-1];
        }
    }
    /*for(i=1;i<=lv;++i)
    {
        for(j=1;j<=lw;++j)fprintf(out,"%hd ",m[i][j]);
        fprintf(out,"\n");
    }*/
    i=lv;
    j=lw;
    while(m[i][j])
    {
        if(m[i][j]==m[i-1][j-1]+1)
        {
            s[++k]=v[i];
            --i;
            --j;
        }
        else
        {
            if(m[i-1][j]==m[i][j])--i;
            else --j;
        }
    }
    fprintf(out,"%hd\n",m[lv][lw]);
    for(i=k;i;--i)fprintf(out,"%hd ",s[i]);
    fprintf(out,"\n");
    fclose(in);fclose(out);
    return 0;
}
