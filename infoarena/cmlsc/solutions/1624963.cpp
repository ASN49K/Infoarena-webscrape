#include<cstdio>
int ma[1025][1025],ma2[1025][1025],v[1025],v2[1025],sol[1025];
int max(int x,int y)
    {if(x>=y)
        return x;
    return y;
    }
int main ()
{freopen ("cmlsc.in","r",stdin);
freopen ("cmlsc.out","w",stdout);
int n,m,i,j;
scanf("%d%d",&n,&m);
for(i=1;i<=n;i++)
    scanf("%d",&v[i]);
for(i=1;i<=m;i++)
    scanf("%d",&v2[i]);
for(i=1;i<=n;i++)
    for(j=1;j<=m;j++)
        if(v[i]==v2[j])
            {ma[i][j]=ma[i-1][j-1]+1;
            ma2[i][j]=2;
            }
        else
            {ma[i][j]=max(ma[i-1][j],ma[i][j-1]);
            if(ma[i][j]==ma[i-1][j])
                ma2[i][j]=1;
            else
                ma2[i][j]=3;
            }
printf("%d\n",ma[n][m]);
i=n;
j=m;
while(i>0&&j>0)
    {if(ma2[i][j]==2)
        {sol[ma[i][j]]=v[i];
        i--;
        j--;
        }
    else
        if(ma2[i][j]==1)
            i--;
        else
            j--;
    }
for(i=1;i<=ma[n][m];i++)
    printf("%d ",sol[i]);
return 0;
}
