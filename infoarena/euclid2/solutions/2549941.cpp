#include <iostream>

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
    std::cin >> n;
    int eredmeny[n];
    for (int i = 0; i < n; i++)
    {
        int a, b;
        std::cin >> a >> b;
        eredmeny[i] = euclid(a, b);
    }

    for (int i = 0; i < n; i++){
        std::cout << eredmeny[i] << "\n";
    }

    return 0;
}
