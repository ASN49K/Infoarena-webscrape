#include <iostream>
#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
void euclid(int a,int b)
{
    int r;
    do{
        r=a%b;
        a=b;
        b=r;
    }while(r);
    g<<a<<endl;
}
int main()
{

    int a,b,n;
    f>>n;
    while(f>>a>>b){
        euclid(a,b);
    }
}
