#include <iostream>
#include <fstream>
using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");

int euclid(int x,int y)
{
    if(x>y)
        return euclid(x-y,y);
    else if(x<y)
        return euclid(x,y-x);
    return x;
}

int main()
{
    int x,y;
    cin>>x>>y;
    cout<<euclid(x,y);
}
