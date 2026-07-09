#include<fstream>

using namespace std;

int euclid(int a, int b)
{
    if(!a%b) return b;
    if(!b%a) return a;
    if(a>b) return euclid(a%b,b);
    if(a<b) return euclid(b%a,a);
}

int main()
{
    int x,a,b;
    ifstream I("euclid.in");
    ofstream O("euclid.out");
    I>>x;
    for(int i=0;i<x;i++)
    {
        I>>a>>b;
        O<<euclid(a,b)<<endl;
    }
    return 0;
}
