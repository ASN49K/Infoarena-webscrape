#include <iostream>
#include <fstream>

using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");

int euclid(int x,int y)
{
    while(y>0)
    {
        int z=x%y;
        x=y;
        y=z;
    }
    return x;
}

using namespace std;
int main() {
    int t;
    cin>>t;
    for(int i=1;i<=t;i++) {
        int x, y;
        in >> x >> y;
        out << euclid(x, y)<<'\n';
    }
}