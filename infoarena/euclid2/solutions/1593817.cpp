#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstdarg>
using namespace std;

int euclid(int a,int b)
{
    if(b==0) return a;
    else return euclid(b,a%b);
}

int main()
{
    freopen("euclid2.out","w",stdout);
    freopen("euclid2.in","r",stdin);
    int load;
    int a;
    int b;
    cin>>load;
    for(register int i=1;i<=load;i++)
    {
        cin>>a;
        cin>>b;
        cout<<euclid(a,b);
        cout<<endl;
    }
}
