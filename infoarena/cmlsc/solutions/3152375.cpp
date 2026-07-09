#include<fstream>
#include<iostream>

using namespace std;

int main() {
    ifstream read("cmlsc.in");
    ofstream write("cmlsc.out");

    int sizeA, sizeB;
    read >> sizeA >> sizeB;
    int *a = (int*)malloc((sizeA + 1) * sizeof(int));
    int *b = (int*)malloc((sizeB + 1) * sizeof(int));
    int *c = (int*)calloc((sizeA + 1) * (sizeB + 1), sizeof(int));

    for (int i = 1; i <= sizeA; i++) {
        read >> a[i];
    }

    for (int i = 1; i <= sizeB; i++) {
        read >> b[i];
    }

    for (int i = 1; i <= sizeA; i++) {
        for (int j = 1; j <= sizeB; j++) {
            if (a[i] == b[j]) {
                c[i * (sizeB + 1) + j] = c[(i - 1) * (sizeB + 1) + j - 1] + 1;
            } else {
                c[i * (sizeB + 1) + j] = max(c[(i - 1) * (sizeB + 1) + j], c[i * (sizeB + 1) + j - 1]);
            }
        }
    }

    write << c[(sizeA + 1) * (sizeB + 1) - 1] << "\n";
    for (int i = 1; i <= sizeA;) {
        for (int j = 1; j <= sizeB;) {
            if (a[i] == b[j]) {
                write << a[i] << " ";
                i++;
                j++;
            } else {
                if (c[(i + 1) * (sizeB + 1) + j] > c[i * (sizeB + 1) + j + 1])
                    i++;
                else j++;
            }
        }
    }
}