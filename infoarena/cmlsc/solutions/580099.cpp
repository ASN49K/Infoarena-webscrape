#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LIM 1026

typedef short Type;

using namespace std;

Type X[LIM], Y[LIM], _B[LIM][LIM];
unsigned char _C[LIM][LIM];
int SizeX, SizeY;


inline Type B(int i, int j)
{
    return _B[i][j];
}

inline void SetB(int i, int j, Type value)
{
    _B[i][j] = value;
}

inline Type C(int i, int j)
{
    return _C[i][j];
}

inline void SetC(int i, int j, Type value)
{
    _C[i][j] = value;
}

void Length()
{
    for (int i=1; i <= SizeX; i++)
        for (int j=1; j<= SizeY; j++)
            if (X[i] == Y[j]) {
                SetC(i,j, C(i-1, j-1) + 1);
                SetB(i,j, 1);
            }
            else if (C(i-1,j) >= C(i, j-1)) {
                SetC(i,j, C(i-1,j));
                SetB(i,j, 2);
            }
            else {
                SetC(i,j, C(i,j-1));
                SetB(i,j, 3);
            }
}

void PrintStr(int i, int j)
{
    if (i==0 || j==0) return;

    if (B(i,j) == 1) {
        PrintStr(i-1,j-1);
        printf("%d ", X[i]);
    }

    else if (B(i,j) == 2) PrintStr(i-1,j);
    else PrintStr(i,j-1);
}


int main()
{
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);

    scanf("%d %d\n", &SizeX, &SizeY);

    for (int i=1; i<=SizeX; i++)
        scanf("%d", &X[i]);

    for (int i=1; i<=SizeY; i++)
        scanf("%d", &Y[i]);

    Length();

    printf("%d\n", C(SizeX, SizeY));

    PrintStr(SizeX, SizeY);

    return 0;
}
