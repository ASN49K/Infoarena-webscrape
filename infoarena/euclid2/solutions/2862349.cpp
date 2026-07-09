#include <fstream>

using namespace std;
ifstream cin("euclid2.in");
ofstream cout("euclid2.out");
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int n , m;
    cin >> n >> m;
    while(m != 0)
    {
        int r = n % m;
        n = m;
        m = r;
    }
    cout << n<<'\n';
    }
    return 0;
}
