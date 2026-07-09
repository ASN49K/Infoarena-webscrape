#include <iostream>

using namespace std;

int main()
{
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);

    int n;

    cin >> n;

    for(int i = 0; i < n; i++)
    {
        int a, b;

        cin >> a >> b;

        while(b != 0)
        {
            int aux = a % b;
            a = b;
            b = aux;
        }

        cout << a << "\n";
    }

    return 0;
}
