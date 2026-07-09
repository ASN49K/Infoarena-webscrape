#include<iostream>
#include<fstream>
using namespace std;
int main()
{
    int a,b,n,r,i;
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    f>>n;
    for(i=0;i<n;i++)
    {
      f>>a>>b;
    if(a<b)
        swap(a,b);
    while(b)
    {
        r=a%b;
        a=b;
        b=r;
    }
    g<<a<<'\n';
    break;
    }
    return 0;


}
