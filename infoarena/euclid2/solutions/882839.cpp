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

        while (a != 0 && b!=0)
        {
            (a > b) ? a%=b : b%=a ;
        }

        if (a != 0)
            OUT << a << "\n" ;
        else
            OUT << b << "\n";
    }

    return 0;
}
