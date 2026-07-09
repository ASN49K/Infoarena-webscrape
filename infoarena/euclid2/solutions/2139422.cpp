#include <iostream>
#include<fstream>
using namespace std;
ifstream f("euclid2.in.txt");
ofstream g("euclid2.out.txt");
int main()
{
    int T,i,a,b,c;
    f>>T;
    for(i=1;i<=T;i++)
    {
        f>>a>>b;
        while(b)
        {
            c=a%b;
            a=b;
            b=c;
        }
        g<<a<<endl;
    }
    f.close();
    g.close();
    return 0;
}
