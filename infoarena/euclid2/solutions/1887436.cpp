#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
ifstream ci("euclid2.in");
    ofstream cou("euclid2.out");
int main()
{

    unsigned int n,i,a,b,c;
    ci>>n;
    for(i=1;i<=n;i++)
    {
    ci>>a>>b;
    c=a%b;
    while(c)
    {
    a=b;
    b=c;
    c=a%b;
    }
    cou<<b<<endl;
    }
    return 0;
}
