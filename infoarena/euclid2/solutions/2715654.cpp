#include<iostream>
#include<fstream>
using namespace std;
int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    int T,a,b;
    f>>T;
    for(int i=0;i<T;i++)
    {
        f>>a;
        f>>b;
        while(a!=b)
        {
            if(a>b)
                a-=b;
            else
                b-=a;
        }
        g<<a<< " ";
    }
    return 0;
}
