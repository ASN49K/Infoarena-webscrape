#include <iostream>
#include <fstream>


int f(int a,int b)
{
    if(!b) return a;
    return f(b,a%b);
}

using namespace std;

int main()
{
    ifstream in("euclid2.in");
    ofstream out("euclid2.out");
    int t,a,b;
    in>>t;
    for(int i=0;i<t;i++)
    {
        in>>a>>b;
        out<<f(a,b)<<endl;
    }
    return 0;
}
