
#include <fstream>
using namespace std;
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
int t,i,a,b;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
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