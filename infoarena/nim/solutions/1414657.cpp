#include<fstream>

using namespace std;

int N,t,x,sum;

int main()
{
    ifstream cin("nim.in");
    ofstream cout("nim.out");

    cin >> t;

    while (t--)
    {
        cin >> N;
        sum = 0;
        for (int i=1; i <= N; i++)
            cin >> x, sum ^= x;
        cout << (sum>0 ? "DA\n" : "NU\n");
    }
    return  0;
}
