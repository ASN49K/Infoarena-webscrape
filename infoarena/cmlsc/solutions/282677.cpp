#include <stdio.h>
int a[1100],b[1100],v[1100][1100],m,n,i,j,sol[1100],l;
int main()
{freopen("cmlsc.in","r",stdin);freopen("cmlsc.out","w",stdout);
 scanf("%d%d",&m,&n);
 for(i=1;i<=m;i++)scanf("%d",&a[i]);
 for(i=1;i<=n;i++)
  {scanf("%d",&b[i]);
   for(j=1;j<=m;j++){if(v[i][j-1]>v[i-1][j])v[i][j]=v[i][j-1];
					     else v[i][j]=v[i-1][j];
		     if(a[j]==b[i])if(v[i-1][j-1]>=v[i][j])v[i][j]=v[i-1][j-1]+1;
		    }
  }
 i=n;j=m;
 printf("%d\n",v[i][j]);
 while(i&&j)
  {if(b[i]==a[j])
    {l++;sol[l]=a[j];
     i--;j--;
    }
      else if(v[i][j]==v[i-1][j])i--;else j--;
  }
 for(i=l;i>=1;i--)printf("%d ",sol[i]);
 fclose(stdin);fclose(stdout);
 return 0;
}