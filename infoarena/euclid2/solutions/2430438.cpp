#include <iostream>
#include <fstream>
using namespace std;
ifstream in("euclid2.in");
ofstream out("euclid2.out");
int main()
{
    int T,d,a,b;
    in>>T;
    for(int i=1;i<=T;i++)
    {
        in>>a>>b;

        while(a!=b)
            if(a>b)
            a=a-b;
            else
            b=b-a;
            out<<a<<endl;
    }
}

