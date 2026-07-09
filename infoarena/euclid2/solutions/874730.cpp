#include <fstream>

using namespace std;
ifstream in ("euclid2.in");
ofstream out ("euclid2.out");
int main()
{
    int t,a,b,i,r;
    in>>t;
    i=1;
    while(t){
    in>>a>>b;
    while(b)
    {
        r=a%b;
        a=b;
        b=r;

    }
    t--;
    out<<a<<endl;
    }
    return 0;
}

