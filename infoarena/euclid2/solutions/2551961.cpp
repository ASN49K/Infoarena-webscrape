#include <fstream>

using namespace std;
int euclid(int a, int b)
{
    if (a%b == 0)
            return b;
    return euclid(b, a%b);
}
int main()
{
    int n, x, y;
    ifstream in("euclid2.in");
    ofstream out("euclid2.out");
    in>>n;
    for(int i =0;i<n; i++)
    {
        in>>x>>y;
        out<<euclid(x,y)<<'\n';
    }
    in.close();
    out.close();
    return 0;
}
