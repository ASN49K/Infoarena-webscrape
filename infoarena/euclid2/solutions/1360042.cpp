#include<cstdio>
#include<string>

using namespace std;

#ifdef HOME
const string inputFile = "input.txt";
const string outputFile = "output.txt";
#else
const string problemName = "euclid2";
const string inputFile = problemName + ".in";
const string outputFile = problemName + ".out";
#endif

int T;

int gcd(int a, int b) {
    int r = a % b;
    while(r) {
        a = b;
        b = r;
        r = a % b;
    }
    return b;
}

int main() {
    int x, y;

    freopen(inputFile.c_str(), "r", stdin);
    freopen(outputFile.c_str(), "w", stdout);

    scanf("%d", &T);

    while(T--) {
        scanf("%d%d", &x, &y);
        printf("%d\n", gcd(x, y));
    }

    return 0;
}
