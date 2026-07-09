#include<fstream> 
using namespace std; 
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");
int main() 
{int m,n, var, v[257], u[257], x[600], i, j, var3=1, tot[500], lungime=0, cheie; 
in>>m>>n; var=m;
for(i=1;i<=m;i++) 
	{in>>v[i]; x[i]=v[i];}
for(j=1;j<=n;j++) 
	{ in>>u[j]; 
    x[var+1]=u[j]; 
	var++;
	}
	
for(j=2;j<=m+n;j++) 
{cheie=x[j];
	i=j-1; 
while(i>0 && x[i]>cheie) 
{x[i+1]=x[i]; 
i=i-1; 
}
x[i+1]=cheie; 
}
for(i=1;i<=m+n;i++) 
	if(x[i]==x[i+1]) 
		{lungime++; 
	    tot[var3]=x[i]; 
		var3++;
		}
		out<<lungime<<'\n'; 
		for(i=1;i<=var3-1;i++) 
			out<<tot[i]<<" "; 
}	
