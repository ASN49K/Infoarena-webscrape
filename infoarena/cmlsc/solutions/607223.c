#include <stdio.h>

int main(void)
{
    FILE *fin,*fout;
    int m,n,v1[1024],v2[1024],i,j,x=0,v[1024];
    
    fin = freopen("cmlsc.in","r",stdin);
    fout = freopen("cmlsc.out","w",stdout);
    
    if(fin == 0)return 0;
    
    scanf("%d %d", &m, &n);
    
    for(i = 0;i < m;i++)
    {
        scanf("%d", &v1[i]);
    }
    for(i = 0;i < n;i++)
    {
        scanf("%d", &v2[i]);
    }
    
    for(i = 0;i < m;i++)
    {
        for(j = 0;j < n;j++)
        {
            if(v1[i] == v2[j])v[x++] = v1[i];
        }
    }
    printf("%d\n",x);
    for(i = 0;i < x;i++)
    {
        printf("%d ",v[i]);
    }
    
    fclose(fin);
    fclose(fout);
    return 0;
}
