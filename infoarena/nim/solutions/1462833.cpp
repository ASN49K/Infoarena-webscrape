#include <iostream>
#include <fstream>

using namespace std;

fstream in("nim.in", ios::in);
fstream out("nim.out", ios::out);

int n,m;

int main()
{

	int i,j,a,b;
	in>>n;

	for(i=1;i<=n;i++)
	{
		in>>m;
		in>>a;
		for(j=2;j<=m;j++)
		{
			in>>b;
			a= (a^b);
		}
		if(a == 0)
			out<< "NU\n";
		else
			out<< "DA\n";
	}

	/*
	cout<< (((1^3)^5)^7)<< "\n";
	cout<< ((4^8)^17)<< "\n";
	*/


        
    in.close();
    out.close();

	return 0;
}

