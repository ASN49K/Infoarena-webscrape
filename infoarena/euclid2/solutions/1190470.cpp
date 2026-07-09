#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    int a,b,c,d,i=1 ;

    ifstream read("euclid2.in");
    read >> a >> b;
    read.close();

    if(a < b)
    {
        c=a;
    }
    else
    {
        c=b;
    }

    for(i=i*i;i<=c;i++)
    {
        if(a%i==0&&b%i==0)
        {
            d=i;
        }
    }
    ofstream write("euclid2.out");
    write << d;
    write.close();

    return 0;
}
