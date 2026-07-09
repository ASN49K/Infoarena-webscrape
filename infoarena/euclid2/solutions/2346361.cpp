#include <fstream>
using namespace std;
ifstream input("euclid2.in");
ofstream output("euclid2.out");
int main()
{
    int n,n1,n2,rest;
    input>>n;
    for(int i=1; i<=n; i++)
    {
        input >> n1 >> n2;
        while(n2)
        {
            rest = n1 % n2;
            n1 = n2;
            n2 = rest;
        }
        g << n1 << '\n';
    }

    input.close();
    output.close();

    return 0;
}
