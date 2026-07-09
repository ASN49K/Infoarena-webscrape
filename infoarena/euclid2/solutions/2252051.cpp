#include <iostream>
#include <fstream>
std::ifstream in("euclid2.in");
std::ofstream out("euclid2.out");

using namespace std;
int n,a,b;
int euclid(int a,int b)
{
    int c;
    while(b)
    {
        c=a%b;
        a=b;
        b=c;
    }
    return a;
}
int main()
{
    in>>n;
    for(int i=0;i<n;i++)
    {
        in>>a>>b;
        out<<euclid(a,b)<<"\n";
    }
    return 0;

}
