#include<fstream.h>
int main(void)
{
int n,a,b,i,c;
ifstream in("euclid2.in");
ofstream out("euclid2.out");
in>>n;
for(i=1;i<=n;i++)
	{
	in>>a>>b;
	while(1)
		{
		if(a>b)	{
			if(a%b==0)
				{
				out<<b<<"\n";
				break;
				}
			a=a%b;
			}
		else
			{
			if(b%a==0)
				{
				out<<a<<"\n";
				break;
				}
			b=b%a;
			}
		}
	//out<<b<<"\n";
	}
in.close();
out.close();
return 0;
}