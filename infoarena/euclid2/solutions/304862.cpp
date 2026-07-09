#include<iostream>
#include<fstream>

using namespace std;



ifstream f ("euclid2.in");
ofstream o ("euclid2.out");

void euclid(long a, long b)
{

if(a%b==0)
        o<<b<<"\n";
    else
        euclid(b,a%b);


}

int main()
{
long i,a,b,T;;
f>>T;
for(i=1;i<=T;i++)
    {
        f>>a>>b;
        euclid(a,b);
    }


 //euclid(9,27);



return 0;}
