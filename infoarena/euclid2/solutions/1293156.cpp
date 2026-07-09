#include <fstream>

using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");

int n,x,y;

int main()
{
    in >> n;

    for(int i = 1; i <= n; i++)
    {
        in >> x >> y;

        while(x != y)
        {
            if(x > y) x-= y;
                else y -= x;
        }
        out << x << '\n';
    }

}
