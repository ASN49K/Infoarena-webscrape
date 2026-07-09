#include <iostream>

using namespace std;

int t[100001];

int main()
{
    int a, b, n;
    cin >> n;
    for(int i = 1; i<= n;i++)
    {
        cin >> a >> b;
        while(b != 0)
        {
            int r = a % b;
            a = b;
            b = r;
        }
        t[i] = a;
    }
    for(int i = 1; i<= n;i++)
        cout << t[i] << " ";
    return 0;
}
