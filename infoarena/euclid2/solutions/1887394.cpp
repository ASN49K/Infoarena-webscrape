#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream ci("euclid2.in");
    ofstream cou("euclid2.out");
    long unsigned int n,i,a,b,c;
    ci>>n;
    for(i=1;i<=n;i++)
    {
    c=1;
     ci>>a>>b;
     if(a<b)
    swap(a,b);
     while(c!=0)
    {
    c=a%b;
    if(c==0)
    break;
    a=b;
    b=c;
    }
    cou<<b<<endl;
    }
    return 0;
}
