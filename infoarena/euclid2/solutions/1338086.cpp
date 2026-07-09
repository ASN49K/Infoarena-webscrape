#include <cstdio>
#include <cctype>
#include <stdint.h>

using namespace std;

#define IN_FILE "euclid2.in"
#define OUT_FILE "euclid2.out"
#define BUFF_SIZE 1 << 15

char a[ BUFF_SIZE ];
int pos = BUFF_SIZE;
FILE *f;
inline char get( ) {
    if( pos == BUFF_SIZE ) {
        fread( a, 1, BUFF_SIZE, f );
        pos = 0;
    }
    return a[ pos++ ];
}
inline uint32_t read( ) {
    char c;
    uint_fast32_t a = 0;
    do {
        c = get( );
    } while( !isdigit( c ) );
    do {
        a = ( a << 1 ) + ( a << 3 ) + ( c - '0' );
        c = get( );
    } while( isdigit( c ) );
    return a;
}
uint32_t inline __declspec ( naked ) __fastcall cmmdc( uint_fast32_t x, uint_fast32_t y ) {
    uint_fast32_t rez;
    __asm__ __volatile__( "movl %1, %%eax;"
                          "movl %2, %%ebx;"
                          "CONTD: cmpl $0, %%ebx;"
                          "je DONE;"
                          "xorl %%edx, %%edx;"
                          "idivl %%ebx;"
                          "movl %%ebx, %%eax;"
                          "movl %%edx, %%ebx;"
                          "jmp CONTD;"
                          "DONE: movl %%eax, %0;" : "=g" ( rez ) : "g" ( x ), "g" ( y ) );
    return rez;
}
int main( ){
    FILE *g;
    register uint_fast32_t T, x, y;

    f = fopen( IN_FILE, "r" );
    T = read( );
    g = fopen( OUT_FILE, "w" );
    while( T-- ) {
        x = y = 0;
        x = read( );
        y = read( );
        fprintf( g, "%d\n", cmmdc( x, y ) );
    }
    fclose( f );
    fclose( g );
    return 0;
}
