#include <stdio.h>

int main(void)
{
    FILE *fin,*fout;
    int m,n,*pv1,*pv2,i,j,x=0,v[1024];
    
    fin = freopen("cmlsc.in","r",stdin);
    fout = freopen("cmlsc.out","w",stdout);
    
    if(fin == 0)return 0;
    
    scanf("%d %d", &m, &n);
    pv1 = malloc(m * sizeof(int));
    pv2 = malloc(n * sizeof(int));
    
    for(i = 0;i < m;i++)
    {
        scanf("%d", pv1+i);
    }
    for(i = 0;i < n;i++)
    {
        scanf("%d", pv2+i);
    }
    
    for(i = 0;i < m;i++)
    {
        for(j = 0;j < n;j++)
        {
            if(*(pv1+i) == *(pv2+j))v[x++] = *(pv1+i);
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
