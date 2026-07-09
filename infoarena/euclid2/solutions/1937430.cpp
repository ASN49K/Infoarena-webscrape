#include <fstream>
#include <future>
#include <queue>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int gcd(int a,int b){if (b==0) return a; return gcd(b,a%b);}
int main()
{
    int t,a,b;
    f>>t;
    std::queue<std::future<int>> futures;
    int threads = 4;
    int i = 0;
    while(t--,i++)
    {
        f>>a>>b;
        if(i%threads==0)
        {
            while(!futures.empty())
            {
                g<<futures.front().get()<<'\n';
                futures.pop();
            }
        }
        futures.push(std::async(std::launch::async,gcd,a,b));
    }
    while(!futures.empty())
    {
        g<<futures.front().get()<<'\n';
        futures.pop();
    }

    return 0;
}
