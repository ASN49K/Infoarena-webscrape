#include<fstream>

using namespace std;

int euclid(int &a, int &b)
{
    int c;
    while(b)
    {
        c=a%b;
        a=b;
        b=c;
    }
    return a;
}

int main()
{
    int x,a,b,c;
    ifstream I("euclid2.in");
    ofstream O("euclid2.out");
    I>>x;
    while(x)
    {
        I>>a>>b;
        O<<euclid(a,b)<<endl;
        x--;
    }
    return 0;
}
