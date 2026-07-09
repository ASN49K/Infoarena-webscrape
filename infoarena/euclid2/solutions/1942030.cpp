#include <iostream>
#include <fstream>
using namespace std;

int euclid(int a,int b)
{
    if(b==0)
        return a;
    else
        euclid(b,a%b);
}

int main()
{int i,a,b,T;
ifstream in("euclid2.in"); ofstream out("euclid2.out");
in>>T;
for(i=0;i<T;i++)
{in>>a>>b;
out<<euclid(a,b)<<'\n';

}
    return 0;
}
