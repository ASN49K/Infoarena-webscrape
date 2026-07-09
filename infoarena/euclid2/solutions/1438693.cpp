#include<iostream >
#include<fstream>
#include<math.h>
using namespace std;
int eu(int a, int b)
{
    int t;
    while (b != 0)
    {
        t = b;
        b = a % b;
        a = t;
    }
    return a;
}


int  main (){
	int i,t,a,b;
	ifstream f("in.txt");
	ofstream g("out.txt");
	f>>t;
	for(i=0;i<=t-1;i++)
		{f>>a>>b;
		g<<eu(a,b)<<endl;
		}
		return 0;






}
