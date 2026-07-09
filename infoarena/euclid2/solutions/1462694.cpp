#include<iostream>
using namespace std;
int cm(int a, int b)
{
    if(!b)
        return a;
    return cm(b,a%b);
}
int main ()
{
    int t,a,b;
    ifstream in("euclid2.in");
    ofstream out("euclid2.out");
    in>>t;
    while(t--)
    {
        in>>a>>b;
        out<<cm(a,b)<<'\n';
    }
}
