#include <fstream>

using namespace std;

int main()
{
    int n, a, b;
    ifstream IN("euclid2.in");
    ofstream OUT("euclid2.out");

    IN>> n;
    for (int i = 0 ; i < n ; i++)
    {
        IN >> a >> b;

        while (a != b)
        {
            (a > b) ? a-=b : b-=a ;
        }

        OUT << a << "\n" ;
    }

    return 0;
}
