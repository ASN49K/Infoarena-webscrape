#include <fstream>
#include <iostream>

#define MAX_LEN 1025

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

typedef unsigned char uchar;
typedef unsigned int uint;

uint max(uint a, uint b) {
    return (a > b) ? a : b;
}


void print_cmlsc(uchar* a,uint size_a, uchar* b,uint size_b) {
    uint **cmlsc = new uint*[size_a+1];
    uint i, j;
    for (i = 0;i <= size_a;++i)
        cmlsc[i] = new uint[size_b + 1]{ 0 };
    for (i = 1;i <= size_a;++i) {
        for (j = 1;j <= size_b;++j) {
            if (a[i] == b[j])
                cmlsc[i][j] = cmlsc[i - 1][j - 1] + 1;
            else
                cmlsc[i][j] = max(cmlsc[i - 1][j], cmlsc[i][j - 1]);
        }
    }
    uint max = cmlsc[size_a][size_b];
    fout << max << '\n';
    uchar* seq = new uchar[max + 1];
    uint k = 1;
    i = size_a;
    j = size_b;
    while (i > 0 && j > 0) {
        if (a[i] == b[j]) {
            seq[k++] = a[i];
            --i;--j;
        }
        else
            if (cmlsc[i - 1][j] > cmlsc[i][j - 1])
                --i;
            else --j;
    }
    for (i = max;i > 0;--i)
        fout << seq[i] << ' ';
}

void read(uchar* vec, uint size) {
    for (uint i = 1;i <= size;++i)
        fin >> vec[i];
}

void print(uchar* vec, uint size) {
    for (uint i = 1;i <= size;++i)
        cout << vec[i] << ' ';
    cout << '\n';
}

int main()
{
    uchar A[MAX_LEN], B[MAX_LEN];
    uint size_A, size_B;
    fin >> size_A >> size_B;
    read(A, size_A);
    read(B, size_B);
    print(B, size_B);

    print_cmlsc(A, size_A, B, size_B);

    return 0;
}
