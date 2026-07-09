#include <fstream>
using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");

int t;
int a,b,c;
int main()
{
    in>>t;
    while(t--)
    {
        in>>a>>b;
        while(b)
        {
            c=a%b;
            a=b;
            b=c;
        }
        out<<a<<'\n';
    }
    return 0;
}
