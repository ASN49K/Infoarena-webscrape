#include<iostream>
#include<fstream>
using namespace std;

int main()
{
    ifstream t1("nim.in");
    ofstream t2("nim.out");
    int t,n,sumxor,a;
    t1>>t;
    for(;t;t--)
    {
        t1>>n;
        sumxor=0;
        for(;n;n--)
        {
            t1>>a;
            sumxor^=a;
        }
        if(sumxor>0) t2<<"DA\n";
        else t2<<"NU\n";
    }
    t1.close();
    t2.close();
    return 0;
}
