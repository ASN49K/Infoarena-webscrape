#include<fstream>
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int a[1025], b[1025], c[1025], n, m, p=0, nr, l;
int minim(int x, int y)
{
	 if(x<y) return x;
	 else
	 if(x>y) return y;
	 else
		 return y;
}

int maxim(int x, int y)
{
	 if(x<y) return y;
	 else
		 return x;
}
void constructie();


int main()
{
	int i, j;
	fin>>n>>m;
	
	for(i=0; i<n; i++)
	{
		fin>>nr;
		a[nr]++;
	}
	
	for(i=0; i<m; i++)
	{
		fin>>nr;
		b[nr]++;
	}
	
l=maxim(n, m);
    
	 constructie();

	fout<<p<<'\n';
	for(i=0; i<=257; i++)
	{
		if(c[i]!=0)
		{
			for(j=1; j<=c[i]; j++)
				fout<<i<<" ";
		}
	}

	
fin.close();
fout.close();
return 0;
}

void constructie()
{
	   int i;
	   for(i=0; i<=257; i++)
	    {
		if(a[i]!=0 && b[i]!=0)
		{
			c[i]=minim(a[i], b[i]);
			p++;
		}
	    }
}
	
