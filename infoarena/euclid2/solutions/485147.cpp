#include<fstream>
#include<iostream>
long a,b,n;
 using namespace std;
int main()
{long a,b,n,r; 
ifstream f("euclid2.in");
ofstream g("euclid2.out");
    f>>n;
for(int i=0;i<n;i++)
    {f>>a;
     f>>b;
     
    while(b!=0)
		{r=a%b;
		 a=b;
		 b=r;
		}
    g<<a<<'\n';}
f.close();
g.close();
return 0;
}
