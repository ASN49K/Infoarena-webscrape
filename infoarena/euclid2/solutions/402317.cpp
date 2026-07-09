#include<iostream.h>
#include<fstream.h>
int main()
{long T,a,b,t,r;
fstream f("euclid2.in",ios::in),g("euclid2.out",ios::out);
f>>T>>a>>b;
for (t=0;t<T;t++)
	{if (a>b)
	r=a%b;
	else
		r=b%a;
	while (r!=0)
		{if (a>b)
		{a=b;
		b=r;
		r=a%b;
		}
		else
			{b=a;
			a=r;
			r=b%a;
			}
		}
		if (a>b)
			g<<b<<endl;
			else
				g<<a<<endl;
f>>a>>b;
}
}