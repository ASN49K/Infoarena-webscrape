//#include <iostream>
//#include <fstream>

#include <stdio.h>

// using namespace std;

int N, A, B;
int cmmdc (int a, int b) 
{
	if (!b)
		return a;
	return cmmdc (b, a%b);
}

int main()
{
	/*ifstream ifs ("euclid2.in");
	ofstream ofs ("euclid2.out");
	int n, a, b;
	ifs>>n;
	for (int i=0; i<n; i++)
	{
		ifs>>a>>b;
		ofs<<cmmdc(a,b)<<endl;
	}*/

	freopen ("euclid2.in", "r", stdin);
	freopen ("euclid2.out", "w", stdout);
	scanf("%i\n", &N);
	for (; N>0; N--)
	{
		scanf ("%i %i\n", &A, &B);
		printf("%i\n", cmmdc(A,B));
	}
	return 0;
}