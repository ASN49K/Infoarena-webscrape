#include<fstream.h>
#include<iostream.h>
ifstream f("euclid2.in") ;
ofstream g("euclid2.out");
int a,b,n;
 void euclid(int a, int b)
{
    if (b == 0) {
	 {g<<a;g<<endl;}
    } else
	euclid(b, a % b);

}
int main()
{

f>>n;
for(int i=1;i<=n;i++)
{f>>a>>b;

	euclid(a,b);   }

g.close();
f.close();
return 0;
}