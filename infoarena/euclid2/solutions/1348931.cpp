#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    int a, b ,t , i, r;
    ifstream in("euclid2.in");
    ofstream out("euclid2.out");
    in>>t;
    for(i=0;i<t;i++)
        {
        in>>a>>b;
        while(b>0)
            {
            r=a%b;
            a=b;
            b=r;
            }
        out<<a<<endl;
        }
    return 0;
}

