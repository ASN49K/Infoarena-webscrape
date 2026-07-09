#include <fstream>
using namespace std;
ifstream in("euclid2.in");
ofstream out("euclid2.out");

unsigned k[200000];
int main()
{
    unsigned T=0;
    in >> T;
    for(unsigned i=0;i<T*2;i++)
    {
        in >> k[i];
    }
    for(unsigned i=0,a=1,b=1;i<T*2;i=i+2)
    {
        a=k[i];
        b=k[i+1];
        if(a%b==0)
        {
            out << b<< "\n";
        }
        else
        {
            while(a%b!=0)
            {
                if(a>b)
                    a=a%b;
                else if(b>a)
                    b=b%a;
            }
            out<<b<<"\n";
        }
    }

    return 0;
}
