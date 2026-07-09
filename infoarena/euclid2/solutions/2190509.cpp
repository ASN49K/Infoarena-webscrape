#include <iostream>
#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int main()
{long long n1,n2,n,i;
f>>n;
for(i=1;i<=n;i++)
   {
    f>>n1>>n2;
    while(n1!=n2)
    {
        if(n1>n2)
            n1=n1-n2;
        else
    n2=n2-n1;
    }
    g <<n1<< endl;}
    return 0;
}
