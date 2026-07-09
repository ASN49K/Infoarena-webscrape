//#include<iostream>
//using namespace std;
//#include <fstream>
//
//int cmmdc(int a,int b)
//{
//	int r;
//	r = a % b;
//	while (r != 0)
//	{
//		a=b;
//		b=r;
//		r=a%b;
//	}
//	return b;
//}
//int main()
//{
//	ifstream inFile;
//	inFile.open("euclid2.in");
//	ofstream outFile;
//	outFile.open("euclid2.out");
//	short n;
//	int a,b;
//	inFile>>n;
//	for (int i=0;i<n;++i)
//	{
//		inFile>>a>>b;
//		outFile<<cmmdc(a,b)<<endl;
//	}
//	outFile.close();
//	inFile.close();
//	return 0;
//}

#include<iostream>
using namespace std;
#include <fstream>

//int cmmdc (int a,int b)
//{
//	while (a!=b)
//	{
//		if (a>b)
//		{
//			a=a-b;
//		}
//		else
//		{
//			b=b-a;
//		}
//	}
//	return a;
//}
//int main()
//{
//	ifstream inFile;
//	inFile.open("euclid2.in");
//	ofstream outFile;
//	outFile.open("euclid2.out");
//	short n;
//	int a,b;
//	inFile>>n;
//	for (int i=0;i<n;++i)
//	{
//		inFile>>a>>b;
//		outFile<<cmmdc(a,b)<<endl;
//	}
//	outFile.close();
//	inFile.close();
//	return 0;
//}

int T, A, B;

int gcd(int a, int b)
{
    if (!b) return a;
    return gcd(b, a % b);
}

int main(void)
{
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);

    scanf("%d", &T);
    for (; T; --T)
    {
        scanf("%d %d", &A, &B);
        printf("%d\n", gcd(A, B));
    }        

    return 0;
}