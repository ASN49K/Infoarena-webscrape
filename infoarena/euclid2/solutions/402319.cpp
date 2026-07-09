#include<iostream.h>
#include<fstream.h>
int main()
{long T,a,b,t;
fstream f("euclid2.in",ios::in),g("euclid2.out",ios::out);
f>>T>>a>>b;
for (t=0;t<T;t++)
{while (a!=b)
{if (a>b)
	a=a-b;
	else
		b=b-a;
}
g<<a<<endl;
f>>a>>b;
}
}