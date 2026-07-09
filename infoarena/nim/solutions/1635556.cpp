#include <fstream>
#include <iostream>
using namespace std;
ifstream in("nim.in");
ofstream out("nim.out");
int main()
{
    int j,n,x,r;
    in>>j;
    for(int i=1;i<=j;i++){
        in>>n;
        in>>x;
        r=x;
        for(int k=1;k<n;k++){
            in>>x;
            r=r^x;
        }
        if(r)
            out<<"DA\n";
        else out<<"NU\n";
    }
    return 0;
}
