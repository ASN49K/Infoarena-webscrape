#include<fstream>
using namespace std;
ifstream cin("nim.in");
ofstream cout("nim.out");
int main()
{
    int t; cin >> t;
    for(int i = 0; i < t; i++)
    {
        int n; cin >> n;
        int rez = false;
        for(int j = 0; j < n; j++)
        {
            int x; cin >> x;
            rez ^= x;
        }
        (rez == false)? cout << "NU" : cout << "DA";
        cout << '\n';
    }
    return 0;
}
