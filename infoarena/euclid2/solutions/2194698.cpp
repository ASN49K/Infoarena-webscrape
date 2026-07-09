#include <iostream>
#include <fstream>
using namespace std;
int t,a,b,i=1;
int main()
{
    ifstream in("euclid2.in");
    ofstream out("euclid2.out");
    in>>t;
    while(i<=t)
    {
        in>>a>>b;
        while(a!=b)
        {
            if(a>b)
            {
                a=a-b;
            }
            else
            {
                if(a<b)
                {
                    b=b-a;
                }
            }
        }
        out<<a<<endl;
        i++;
    }
    return 0;
}
