#include <fstream>
using namespace std;
ifstream in("euclid2.in");
ofstream out("euclid2.out");
int euclid(int a, int b)
{
    if(b==0)
    return a;

    return euclid(b, a%b);
}
int main()
{
    int n, i, a, b;
    in >> n;
    for(i = 1; i <= n; i++)
    {
        in >> a >> b;
        out << euclid(a, b) << '\n';
    }
    return 0;
}