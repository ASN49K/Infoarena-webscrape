#include<fstream>
using namespace std;
short a[1026],b[1026],v[1026][1026],rez[1026];
int max(int r,int e) {if(e>r) return e;return r;}
int main()
{int i,j,n,m,nr=0;
ifstream in("cmlsc.in");
in>>n>>m;
for(i=1;i<=n;i++)
	in>>a[i];
for(i=1;i<=m;i++)
	in>>b[i];
in.close();
for(i=1;i<=n;i++)
	for(j=1;j<=m;j++)
		{if(a[i]==b[j])
			v[i][j]=1+v[i-1][j-1];
		else
			v[i][j]=max(v[i-1][j],v[i][j-1]);
		}
for(i=n,j=m;i;)
	{if(a[i]==b[j])
            rez[++nr]=a[i],i--,j--;
	else 
		if(v[i-1][j]<v[i][j-1])
            j--;
	else
		i--;
	}
ofstream out("cmlsc.out");
out<<nr<<'\n';
for(i=nr;i>0;i--)
	out<<rez[i]<<" ";
out.close();
return 0;
}
