#include<iostream>
#include<fstream>
using namespace std;

int main()
{
    ifstream in("euclid2.in");
    ofstream out("euclid2.out");
    int a,b,d,t,i;
    in>>t;
    for(i=1;i<=t;i++)
    {in>>a>>b;
    d=a%b;
    while(d!=0)
    {
        a=b;
        b=d;
        d=a%b;
    }
    out<<b<<endl;}
    in.close();
    out.close();
    return 0;
}

