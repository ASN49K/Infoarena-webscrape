#include<iostream>
#include<fstream>
using namespace std;
    ifstream f("euclid2.in");
    ofstream o("euclid2.out");
    int euclid(int a,int b)
    {
        int r;
        while(b)
        {
            r=a%b;
            a=b;
            b=r;
        }
        return a;
    }
int main()
{
    int t,a,b;
    f>>t;
        for(int i=11;i<=t;i++)
        {
            f>>a>>b;
            o<<euclid(a,b)<<endl;
        }
}
