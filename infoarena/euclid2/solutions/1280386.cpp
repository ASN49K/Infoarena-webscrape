#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    int a,b,r,i,n;

    fstream input("euclid2.in",ios::in);
    fstream output("euclid2.out",ios::out);
    input>>n;
    for(i=1;i<=n;i++)
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
