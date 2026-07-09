#include<iostream>
#include<fstream>
#include<algorithm>

using namespace std;
int a,b,n,i,sol;
int euclid(int a,int b){
    if(b==0)
        return a;
    else
        return euclid(b,a%b);
}
int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");

    f>>n;
    for(i=1;i<=n;i++)
    {
        f>>a>>b;

        g<<euclid(b,a)<<"\n";

    }
}
