#include<fstream.h>
ifstream f("euclid2.in");
ofstream g("euclid2.out");
long T, A, B;
long cmmdc(int A, int B)
	{
	if (!B)	return  A;
	else		return cmmdc(B, A%B);
	}
int main()
	{
	f>>T;
	for (int i=1;i<=T;i++)
		{
		f>>A; f>>B;
		g<<cmmdc(A,B)<<endl;
		}
	f.close(); g.close();
	return 0;
	}