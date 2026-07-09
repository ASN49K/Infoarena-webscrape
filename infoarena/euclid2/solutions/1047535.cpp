#include<fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int a,b;

int euclid(int a,int b)
{
    if(a==b)
        return a;
    else
        if(a>b)
            return euclid(a-b,b);
        else
            return euclid(a,b-a);
}

int main()
{
    f>>a>>b;
    g<<euclid(a,b);
    return 0;
}
