#include <iostream>
#include <fstream>

using namespace std;
int T, a, b, c;
int i;
ifstream in("euclid2.in");
ofstream out("euclid2.out");
int main()
{

    in>>T;
    for(i=0;i<T; i++)
    {
        in>>a>>b;
        while (b!=0)
        {
            c=a%b;
            a=b;
            b=c;
        }
        out<<a<<"\n";
    }
    in.close();
    out.close();
    return 0;
}
