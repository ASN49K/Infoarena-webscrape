#include <iostream>
#include <fstream>
using namespace std;
ifstream in("euclid2.in");
ofstream out("euclid2.out");
int main()
{
    int T,a,b;
    in>>T;
    for(int i=1;i<=T;i++)
    {
        in>>a>>b;
        while(b)
        {
            int r=a%b;
            a=b;
            b=r;
        }
            out<<a<<"\T";
    }
    in.close();
    out.close();
    return 0;
}

