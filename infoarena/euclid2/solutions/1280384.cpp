#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    int a,b,r;

    fstream input("euclid2.in",ios::in);
    fstream output("euclid2.out",ios::out);
    input>>a;
    while(!input.eof())
    {
        input>>a>>b;
        if(a<b)
        {
            r=a;
            a=b;
            b=r;
        }
        while(b!=0)
        {
            r=a%b;
            a=b;
            b=r;
        }
        output<<a<<"\n";
    }
    input.close();
    output.close();
    return 0;
}
