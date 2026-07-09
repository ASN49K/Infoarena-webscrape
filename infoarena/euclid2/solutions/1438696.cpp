#include<iostream>
#include<fstream>
#include<math.h>
using namespace std;
int eu(int a, int b)
{
    int p;
    while (b != 0)
    {
        p = b;
        b = a % b;
        a = p;
    }
    return a;
}


int  main (){
	int i,t,a,b;
	ifstream f("euclid2.in");
	ofstream g("euclid2.out");
	f>>t;
	for(i=0;i<=t-1;i++)
		{f>>a>>b;
		g<<eu(a,b)<<endl;
		}
		return 0;






}
