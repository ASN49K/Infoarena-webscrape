#include <fstream>

using namespace std;
ifstream i("euclid2.in");
ofstream o("euclid2.out");
int main()
{
    int A, b, r, T, i;
    i>>T;
    for(A=1; A<=T; A++)
    {
        i>>a;
        i>>b;
        while(b)
        {
            r=a%b;
            a=b;
            b=r;
        }
        o<<a<<endl;
    }
    return 0;
}
