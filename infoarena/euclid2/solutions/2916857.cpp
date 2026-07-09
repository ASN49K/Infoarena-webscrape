#include <iostream>
#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int x1,x2,t;
int main()
{
    f>>t;
    int var;
    while(t--){
        f>>x1>>x2;
        while(x2!=0)
        {
                var=x2;
                x2=x1%x2;
                x1=var;
        }
        cout<<x1<<'\n';
    }
    return 0;
}
