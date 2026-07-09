#include <stdio.h>

#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops,fast-math,inline")
#pragma GCC target ("avx2,bmi,bmi2,lzcnt,popcnt")

FILE *fin = fopen("nim.in", "r");
FILE *fout = fopen("nim.out", "w");

char buff[4096]; int id;
char outBuff[4096]; int id2;

static inline char readCh( ) {
    ++id;
    if (id == 4096) { id = 0; fread(buff, sizeof(char), 4096, fin); }
    return buff[id];
}

static inline bool isdig(char ch) {
    return '0' <= ch && ch <= '9';
}
static inline void readInt(int &num) {
    char ch;
    while (!isdig(ch = readCh( )));
    num = ch - '0';
    while (isdig(ch = readCh( )))
        num = num * 10 + ch - '0';
}

static inline void writeStr(const char *str) {
    outBuff[id2++] = str[0];
    outBuff[id2++] = str[1];
    outBuff[id2++] = str[2];
}

int q, n, sum, cur;
static inline void solve( ) {
    readInt( n ); sum = 0;
    while (n--) { readInt( cur ); sum ^= cur; }
    if (sum == 0) writeStr( "NU\n" );
    else writeStr( "DA\n" );
}

int main( ) {
    readInt( q );
    while (q--) solve( );
    fwrite(outBuff, sizeof(char), id2, fout);
    return 0;
}
