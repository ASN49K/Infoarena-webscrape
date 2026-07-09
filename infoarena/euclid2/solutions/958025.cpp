#include<iostream>
#include<fstream>
using namespace std;

int t,a,b,i,r,c;
ifstream f("euclid2.in");
ofstream g("euclid2.out");


 int cmmdc (int a, int b)
{
	int r;
	while(a%b!=0)
	{r=a%b;
	a=b;
	b=r;
	}



	return b;
}
int main()
{f>>t;
    for(i=1;i<=t;i++)
{f>>a>>b;
c=cmmdc(a,b);
g<<c<<endl;
}


g.close();
f.close();

}


