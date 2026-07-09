#include <fstream>
int a,b,t;
using namespace std;
int cmmdc(int a, int b)
{
    if(!b)return a;
    return cmmdc(b,a%b);
}
int main()
{
    ifstream in("euclid2.in");
    ofstream out("euclid2.out");
    in>>t;
        while (t>=1)
        {
            in>>a>>b;
            out<<cmmdc(a,b)<<'\n';
            t--;
        }


    return 0;
}
