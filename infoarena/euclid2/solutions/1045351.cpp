#include <iostream>
#include <fstream>
using namespace std;
int t,i;
long a,b;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int euclid(int a,int b)
{
	int r=a%b;
   while(r)
    {
        
        a=b;
        b=r;
	r=a%b;
    }
    return b;

}
int main()
{
    f>>t;
    for(i=1;i<=t;i++)
    {
        f>>a>>b;
        g<<euclid(a,b)<<endl;
    }
    f.close();
    g.close();
    return 0;
}