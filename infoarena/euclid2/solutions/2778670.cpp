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
    long long a,b;
    int t;
    f>>t;
        for(int i=1;i<=t;i++)
        {
            f>>a>>b;
            o<<euclid(a,b)<<endl;
        }
}
