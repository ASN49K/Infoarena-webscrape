#include <fstream>
std::ifstream cin("euclid2.in");
std::ofstream cout("euclid2.out");
using namespace std;

int main()
{
    int T,a,b,aux;
    cin>>T;
    while(cin>>a>>b)
    {
        while(a%b)
        {   aux=a;
            a=b;
            b=aux%b;

        }
    }
    cout<<a;
    return 0;
}
