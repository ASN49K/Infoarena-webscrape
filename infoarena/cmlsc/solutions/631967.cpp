#include<fstream> 
using namespace std; 
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");
int main() 
{int m,n, var, v[257], u[257], x[600], i, j, var3=1, tot[500], lungime=0; 
in>>m>>n; var=m;
for(i=1;i<=m;i++) 
	{in>>v[i]; x[i]=v[i];}
for(j=1;j<=n;j++) 
	{ in>>u[j]; 
    x[var+1]=u[j]; 
	var++;
	}
	
sort(x+1,x+m+n+1); 
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
