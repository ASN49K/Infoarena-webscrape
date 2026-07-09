#include<fstream>

using namespace std;

int main()
{
    int x,a,b,c;
    ifstream I("euclid2.in");
    ofstream O("euclid2.out");
    I>>x;
    while(x)
    {
        I>>a>>b;
         while(b)
    {
        c=a%b;
        a=b;
        b=c;
    }
        O<<a<<endl;
        x--;
    }
    return 0;
}
