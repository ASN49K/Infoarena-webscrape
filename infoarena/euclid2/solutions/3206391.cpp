#include <fstream>

using namespace std;

ifstream cin("euclid2.in");
ofstream cout("euclid2.out");
int main()
{
    int t, a, b, i, aux;
    cin >> t;
    for(i = 1; i <= t; i++)
    {
        cin >> a >> b;
        if(a < b)
        {
            aux = b;
            b = a;
            a = aux;
        }
        while(a % b != 0)
        {
            aux = b;
            b = a % aux;
            a = aux;
        }
        cout << b << endl;
    }
    return 0;
}
