#include<iostream>
#include<fstream>
using namespace std;
int main()
{
    ifstream f("euclid2.in");
    ofstream o("euclid2.out");
    int t,a,r,b;
    f>>t;
    {
        for(int i=11;i<=t;i++)
        {
            f>>a>>b;
            while(b!=0)
            {
                r=a%b;
                a=b;
                b=r;
            }
            cout<<a<<endl;
        }
    }
}
