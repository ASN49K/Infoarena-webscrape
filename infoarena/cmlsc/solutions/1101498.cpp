#include<fstream>
#include<iostream>
using namespace std;
int x[1100][1100];
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int main()
{int a[1100],b[1100],n,m,c[1100],pas=1,i,j,max=0;
fin>>n;
fin>>m;
for(i=1;i<=n;i++)
    fin>>a[i];
for(i=1;i<=m;i++)
    fin>>b[i];
for(i=1;i<=n;i++)
    for(j=1;j<=m;j++)
        if(a[i]==b[j])
            x[i][j]=x[i-1][j-1]+1;
            
        else
            {if(x[i][j-1]>x[i-1][j])
                x[i][j]=x[i][j-1];
            else
                x[i][j]=x[i-1][j];
			}
fout<<x[n][m]<<endl;
for(i=n,j=m;j>=1&&i>=1; )
	{if(a[i]==b[j])
		{c[pas]=a[i];
		pas++;
		i--;
		j--;
		}
	else
		{if(x[i-1][j]>x[i][j-1])
			i--;
		else
			j--;
		}
	}
for(i=pas-1;i>=1;i--)
    fout<<c[i]<<' ';
fin.close();
fout.close();
return 0;
}