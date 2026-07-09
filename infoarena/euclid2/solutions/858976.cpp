#include <iostream>
using namespace std;
int n,a,b,i;
int cmmdc(int a, int b)
{
    if (!b) return a;
    return cmmdc(b, a % b);
}
 
int main()
{
    cin>>n;
    for (i=1;i<=n;i++)
    	{
    		cin>>a>>b;
    		cout<<cmmdc(a,b)<<"\n";
    	}
    		return 0;}