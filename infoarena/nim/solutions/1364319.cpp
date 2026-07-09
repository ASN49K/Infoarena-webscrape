#include<cstdio>
#include<string>

using namespace std;

#ifdef HOME
const string inputFile = "input.txt";
const string outputFile = "output.txt";
#else
const string problemName = "nim";
const string inputFile = problemName + ".in";
const string outputFile = problemName + ".out";
#endif

int T, N;

int main() {
    int sum = 0, i, x;

    freopen(inputFile.c_str(), "r", stdin);
    freopen(outputFile.c_str(), "w", stdout);

    scanf("%d", &T);

    while(T--) {
        scanf("%d", &N);

        for(i = 1, sum = 0; i <= N; i++) {
            scanf("%d", &x);
            sum ^= x;
        }

        printf("%s\n", sum ? "DA" : "NU");
    }

    return 0;
}
