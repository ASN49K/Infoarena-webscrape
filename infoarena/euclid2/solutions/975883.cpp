#include <iostream>
#include <fstream>
using namespace std;

int cmmdc(unsigned long a, unsigned long b);

int main()
{
    ifstream fi("euclid2.in");
    ofstream fo;
    fo.open("euclid2.out");

    int T;
    fi>>T;

    unsigned long a,b;

    for(int i=1;i<=T;i++)
    {
      fi>>a>>b;
     fo<<cmmdc(b,a)<<endl;

    }

    return 0;
}

int cmmdc(unsigned long a, unsigned long b)
{
    if(b%a==0)return a;
      else cmmdc(b%a,a);
}
