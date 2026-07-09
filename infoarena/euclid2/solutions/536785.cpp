#include <fstream.h>
#include <iostream.h>
int main()
{
	int a,b,r,n,i;
	fstream fin("euclid2.in",ios::in);
	fstream fout("euclid2.out",ios::out);
	fin>>n;
	for(i=1;i<=n;i++)
	{
		fin>>a>>b;
		do
		{
			r=a%b;
			a=b;
			b=r;
		}
		while(r!=0);
		fout<<a<<endl;
	}
	fin.close();
	fout.close();
	return 0;
}