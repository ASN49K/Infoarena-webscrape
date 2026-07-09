#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream ci("euclid2.in");
    ofstream cou("euclid2.out");
    int n,i,a,b,c;
    ci>>n;
    for(i=1;i<=n;i++)
    {
     ci>>a>>b;
     while(b!=1)
    {
    c=a%b;
    if(c==0)
    break;
    b=a;
    a=c;
    }
    cou<<b;
    }
    return 0;
}
