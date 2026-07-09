#include<fstream>

using namespace std;

int euclid(int a, int b)
{
    if(!b) return a;
    return euclid(b,a%b);
}

int main()
{
    int x,a,b;
    ifstream I("euclid2.in");
    ofstream O("euclid2.out");
    I>>x;
    for(int i=0;i<x;i++)
    {
        I>>a>>b;
        O<<euclid(a,b)<<endl;
    }
    return 0;
}
