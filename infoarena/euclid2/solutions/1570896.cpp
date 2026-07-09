#include <iostream>
#include <fstream>
int a,b,c,v;
using namespace std;

int main()
{
    ifstream r("euclid2.in");
    ofstream t("euclid2.out");
    r>>c;
    for (int i=1;i<=c;i++)
    {
        r>>a>>b;
        while(b!=0)
        {
            v=a%b;
            a=b;
            b=v;
        }
        t<<a<<"\n";
    }
}
