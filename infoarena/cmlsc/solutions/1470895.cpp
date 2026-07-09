#include <fstream>
#include <stdint.h>
#include <iostream>
#define NMAX 1030
using namespace std;
uint8_t v1[NMAX], v2[NMAX], v3[NMAX];
short int N, M, m[NMAX][NMAX], cont;
ofstream output("cmlsc.out");

void f(int x, int y) {
    if(x == 0 || y == 0)
        return;

    if(m[x][y] > max(m[x][y-1], m[x-1][y])) {
        v3[++cont] = v1[x];
        f(x-1,y-1);
    }
    else 
        if(m[x-1][y] == m[x][y])
            f(x-1,y);
        else
            f(x,y-1);
 }
        
int main(void) {
    ifstream input("cmlsc.in");
    
    input >> N >> M;
    for(int i = 1; i <= N; i++)     input >> v1[i];
    for(int i = 1; i <= M; i++)     input >> v2[i];

   
    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= M; j++)
            if(v1[i] == v2[j])
                m[i][j] = 1 + m[i-1][j-1];
            else
                m[i][j] = max(m[i-1][j], m[i][j-1]);

    int max1 = 0;
    for(int i = 1; i <= M; i++)
        if(m[N][i] > max1)
            max1 = m[N][i];
    output << max1 << endl;
    f(N, M);

    for(int i = cont; i > 0; i--)
        output << v3[i] << " ";
    return 0;
}  
            
