#include <fstream>
using namespace std;
ifstream in("euclid2.in");
ofstream out("euclid2.out");
int main()
{
    int n,a,b;
    in>>n;
    for(int i=1;i<=n;i++)
    {
        in>>a>>b;
        while(b)
            {
                int r=a%b;
                a=b;
                b=r;
            }
                out<<a;
                out<<endl;
    }
    return 0;
}
