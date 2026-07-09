#include <fstream>

using namespace std;

ifstream cin("eculid2.in");
ofstream cout("eculid2.out");

int main()
{
    int t;
    cin >> t;
    int n1, n2, r;

    while(t--)
    {
        cin >> n1 >> n2;

        while(n2 != 0)
        {
            r = n1 % n2;
            n1 = n2;
            n2 = r;
        }
       cout << n1 << "\n";
    }

    return 0;
}
