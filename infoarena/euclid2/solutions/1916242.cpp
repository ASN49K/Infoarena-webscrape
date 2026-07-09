#include <iostream>
#include <fstream>
using namespace std;
ifstream in("euclid2.in");
ofstream out("euclid2.out");
int main()
{
    int T,a,b,m,i;
    in>>T;
    while(T!=0)
    {
        in>>a>>b;
        if(a<b)
            m=a;
        else
            m=b;
        for(i=m;i>0;i--)
            if(a%i==0&&b%i==0){
                out<<i<<endl;
                break;
            }
        T--;
    }
    return 0;
}

