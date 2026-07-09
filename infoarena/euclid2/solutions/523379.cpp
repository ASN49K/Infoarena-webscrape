#include<fstream.h>
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int n;
long a, b;
int main()
{f>>n;
 for(int i=1;i<=n;i++)
    {f>>a>>b;
	int r=a%b;
	 while(r != 0)
        {a = b;
		 b = r;
		 r = a % b;
        }
	g<<b<<"\n";
	}
g.close();
f.close();
return 0;
}
