#include<fstream.h>
ifstream in("euclid2.in");
ofstream out("euclid2.out");

unsigned long a,b,t;

int euclid(unsigned long a, unsigned long b)
{
unsigned long int r;
while(r)
	{r=a%b;a=b;b=r;}
return a;

}
int main()
{
in>>t;
while(t)
	{in>>a>>b;out<<euclid(a,b)<<'\n';t--;}
return 0;
}