#include <fstream>
#include <future>
#include <vector>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int gcd(int a,int b){if (b==0) return a; return gcd(b,a%b);}
int main()
{
    int t,a,b;
    f>>t;
    std::vector<std::future<int>> futures;
    while(t--)
    {
        f>>a>>b;
        futures.push_back(std::async(std::launch::async,gcd,a,b));
    }
    for(auto it = futures.begin();it!=futures.end();++it)
        g<<it->get()<<'\n';
    return 0;
}
