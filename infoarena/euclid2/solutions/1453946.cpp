#include <iostream>
 
using namespace std;
 
long long dc(long long a, long long b)
{
    long long r=b;
     
    while(r)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}
 
int main ()
{
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);
     
    long long a,b,t;
     
    cin >> t;
     
    for (int i=0; i<t; i++)
    {
        cin >> a >> b;
        if (b==0) b=a;
        cout << dc(a,b) << "\n";
    }
     
     
     
return 0;
}
