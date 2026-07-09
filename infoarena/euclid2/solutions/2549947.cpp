#include <fstream>

ifstream cin("euclid2.in");
ofstream cout("euclid2.out");

int euclid(int a, int b){\
    while (b > 0){
        int t = a % b;
        a = b;
        b = t;
    }

    return a;
}

int main()
{
    int n;
    cin >> n;
    int eredmeny[n];
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        eredmeny[i] = euclid(a, b);
    }

    for (int i = 0; i < n; i++){
        cout << eredmeny[i] << "\n";
    }

    return 0;
}
