#include<stdio.h>
inline int max(int a,int b)
{return ((a>b)?a:b);
}
FILE *f=fopen("cmlsc.in","r"),*g=fopen("cmlsc.out","w");
int n,z,v1[1055],np[1055],k,v2[1055],a[1055][1055];
void citire()
{int i;
fscanf(f,"%d",&z);
fscanf(f,"%d",&n);
for(i=1;i<=z;i++)
	{fscanf(f,"%d",&v1[i]);
	}
for(i=1;i<=n;i++)
	{fscanf(f,"%d",&v2[i]);
	}
}
int main()
{int i,j;
citire();
for(i=1;i<=z;i++)
	{for(j=1;j<=n;j++)
		{if(v1[i]==v2[j])
			{a[i][j]=1+a[i-1][j-1];
			}
		else
			{a[i][j]=max(a[i][j-1],a[i-1][j]);
			}
		}
	}
j=n;
i=z;k=0;
while(a[i][j])
	{if(v1[i]==v2[j])
		{np[k++]=v1[i];i--;j--;
		}
	else
		{if(a[i][j-1]>a[i-1][j])
			{j--;
			}
		else
			{i--;
			}
		}
	}
fprintf(g,"%d\n",k);
for(i=k-1;i>=0;i--)
	{fprintf(g,"%d ",np[i]);
	}
fclose(f);
fclose(g);
return 0;
}
