#include <iostream>
#include <fstream>
using namespace std;
int euclid(int a,int b)
{
    if(b==0)
        return a;
    return euclid(b,a%b);
}

int main()
{
    int T,a,b;
    ifstream f("euclid2.in");
    ofstream g("euclid2.out",ios::app);
    f>>T;
    for(;T;T--)
    {
        f>>a>>b;
        g<<euclid(a,b)<<endl;
    }
    return 0;
}
