#include <fstream>

using namespace std;

int euclid(int a, int b)
{
    if (!b)
        return a;
    return euclid(b, a % b);
}
int main()
{
    ifstream cin("euclid2.in");
    ofstream cout("euclid2.out");
    int n , a, b, r, cmmdc;
    cin >> n;
    for(int i = 0; i < n; i ++)
    {
        cin >> a >> b;
       cout << euclid(a, b) << endl;
    }
    return 0;
}
