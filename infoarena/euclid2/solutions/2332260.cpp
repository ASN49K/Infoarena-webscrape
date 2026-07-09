#include <iostream>
#include <fstream>

using namespace std;
ifstream in("euclid2.in");
ofstream out("euclid2.out");

int a,b,t,n;
int main()
{
    in>>n;
   while(n)
   {
        n--;
        in>>a>>b;
        if(a<b)
        {
            t=a;
            a=b;
            b=t;
        }
        while(b)
        {
            t=b;
            b=a%b;
            a=t;
        }
        out<<a<<'\n';
    }
}




