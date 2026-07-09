#include <fstream>
#include <iostream>
/// foloseste define
using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

const int Max = 1025;

int N, M, A[Max], B[Max];
int s[Max], k;

void Read()
{
    f >> M >> N;

    for(int i=0; i<M; i++)
        f >> A[i];

    for(int i=0; i<N; i++)
        f >> B[i];
}

void F()
{
    int index = 0;
    for(int i=0; i<M; i++)
        for(int j=index; j<N; j++)
            if(A[i] == B[j])
            {
                index = j + 1;
                s[k++] = A[i];
            }
}

void Display()
{
    g << k << endl;
    for(int i=0; i<k; i++)
        g << s[i] << " ";
}

int main()
{
    Read();
    F();
    Display();
    return 0;
}
