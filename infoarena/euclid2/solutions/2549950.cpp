#include <fstream>

std::ifstream fin("euclid2.in");
std::ofstream fout("euclid2.out");

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
    fin >> n;
    int eredmeny[n];
    for (int i = 0; i < n; i++)
    {
        int a, b;
        fin >> a >> b;
        eredmeny[i] = euclid(a, b);
    }

    for (int i = 0; i < n; i++){
        fout << eredmeny[i] << "\n";
    }

    return 0;
}
