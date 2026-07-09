#include <fstream>

using namespace std;
ifstream in("euclid2.in");
ofstream out("euclid2.out");

int main()
{
    int T;
    int64_t a,b;
    in>>T;
    while(T--)
    {
        in>>a>>b;
        int64_t r;
        while(b)
        {
            r=a%b;
            a=b;
            b=r;
        }
        out<<a<<'\n';
    }
    in.close();out.close();return 0;
}
