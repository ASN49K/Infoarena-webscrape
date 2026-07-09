#include <fstream>

using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");

int n,a,b,r;

int main()
{
    in>>n;
    while(n)
        {

            in>>a>>b;
            while(b)
            {
                r=a%b;
                a=b;
                b=r;
            }
            out<<a<<'\n';
            n--;
        }

    return 0;
}
