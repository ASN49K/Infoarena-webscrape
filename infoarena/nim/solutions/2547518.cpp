#include <iostream>
#include <fstream>

using namespace std;

ifstream f("nim.in");
ofstream o("nim.out");

int i,j,n,t,sum,nr;

int main()
{
    f >> t;
    for(j=1;j<=t;++j){
        f >> n;

        f >> nr;
        sum=nr;
        for(i=2;i<=n;++i){
            f >> nr;
            sum^=nr;
        }
        if(!sum)
            o << "NU\n";
        else
            o << "DA\n";
    }
    return 0;
}
