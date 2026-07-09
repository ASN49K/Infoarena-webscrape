#include <iostream>
#include<fstream>


using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

void Euclid(int a , int b)
{
    int c=a%b;
    while(b>0)
    {
        c=a%b;
        a=b;
        b=c;
    }
    g<<a<<"\n";
}

void Read()
{
    int a,i ,b,n;
    f>>n;
    for(i=1;i<=n;i++)
    {
        f>>a>>b;
        Euclid(a,b);
    }
}



int main()
{
    Read();
    return 0;
}
