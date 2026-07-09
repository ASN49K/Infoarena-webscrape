#include <fstream>

using namespace std;

int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    int a, b, t, i, r;
    f>>t;
    for(i=1;i<=t;i++)
    {
        f>>a>>b;
        if(a<b){
            while(a!=0)
            {
                r=b%a;
                b=a;
                a=r;
            }
            g<<b<<endl;
        }else{
            while(b!=0)
            {
                r=a%b;
                a=b;
                b=r;
            }
            g<<a<<endl;
        }
    }
    return 0;
}
