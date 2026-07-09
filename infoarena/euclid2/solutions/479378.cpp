#include <fstream>
#include <iostream>
using namespace std;

long i,a,b,n;

long eucl (long a, long b)
{
    if(b==0)
        return a;
    else
        return eucl(b,a%b);
}
int main()
{
    ifstream in("euclid2.in");
    ofstream out("euclid2.out");
    in>>n;
    for(i=1;i<=n;i++)
    {
      in>>a>>b;
      out<<eucl(a,b)<<'/n';
    }
    return 0;
}
