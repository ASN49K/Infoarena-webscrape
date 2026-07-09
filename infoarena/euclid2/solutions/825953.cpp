#include<iostream>
#include<fstream>
using namespace std;
int main()
{int t,a,b;
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    f>>t;
    while(t)
    {
        f>>a; f>>b; t--;
        while(a!=b)
        {
            if(a<b)b=b-a;
            else a=a-b;
        }
        g<<a<<"\n";
    }
    f.close();
    g.close();
}
