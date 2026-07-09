#include <fstream>
using namespace std;

ifstream cin("euclid2.in");
ofstream cout("euclid2.out");

int main()
{
    int a, n;
    cin >> a;
    for(int i = 1; i <= a; ++i){
        int m;
        cin >> n >> m;
        while(m != 0)
        {
            int r = n % m;
            n = m;
            m = r;
        }

    cout << n << endl;
    }
    return 0;
}
