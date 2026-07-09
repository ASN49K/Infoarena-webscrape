#include <iostream>
#include <fstream>
int a,b,n,v;
using namespace std;

int main()
{
    ifstream r("euclid2.in");
    ofstream t("euclid2.out");
    r>>n;
    for (int i=1;i<=n;i++)
    {
        r>>a>>b;
        while(b!=0)
        {
            v=a%b;
            a=b;
            b=v;
        }
        t<<a<<endl;
    }
}
