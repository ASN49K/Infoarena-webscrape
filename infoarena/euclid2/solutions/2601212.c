#include<stdlib.h>
#include<stdio.h>


static inline int getint ( char* buffer, int buffer_size, int* index, FILE *fin ){
    int b = 0;
    int cont = 1;
    while ( cont ){
        if ( (*index) >= buffer_size ){
            fread( buffer, 1, buffer_size, fin);
            (*index) = 0;
        }
        while ( buffer[ (*index) ] >= '0' && buffer[ (*index) ] <= '9') {
            b *= 10;
            b += buffer[ (*index) ] - '0';
            (*index)++;
        }
        if ( (*index) != buffer_size){
            (*index)++;
            cont = 0;
        }
    }
    return b;
}
#define nextint() getint(buffer, buffer_size, index, in)

int euclid ( int a, int b ){
    int c = -1;
    while( c != 0 ){
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}

int main(){
    FILE *in = fopen( "euclid2.in", "r" );
    char *buffer;
    int buffer_size = 8192, idx = buffer_size, *index = &idx;
    buffer = malloc ( sizeof(char)*(buffer_size + 1) );
    buffer[ buffer_size] = NULL;

    FILE *out = fopen( "euclid2.out", "w" );
    char *out_buffer[2];
    int curr_buffer = 0, out_count = 0, out_buffer_size = 8192, overflow = 12;
    out_buffer[0] = malloc ( sizeof(char)*(out_buffer_size + overflow) );
    out_buffer[1] = malloc ( sizeof(char)*(out_buffer_size + overflow) );

    int n = nextint();
    for( int i = 0; i < n; i++ ){
        int a = sprintf( out_buffer[ curr_buffer] + out_count, "%d\n", euclid( nextint(), nextint()));
        out_count += a;
        if( out_count >= out_buffer_size ){
            fwrite( out_buffer[ curr_buffer], 1, out_buffer_size, out);
            out_count -= out_buffer_size;
            strncpy( out_buffer[ !curr_buffer], out_buffer[ curr_buffer] + out_buffer_size, out_count);
            curr_buffer = !curr_buffer;
        }
    }
    fwrite( out_buffer[ curr_buffer], 1, out_count, out);
    free( buffer);
    free( out_buffer[0]);
    free( out_buffer[1]);
    fclose( out);
    fclose( in);
    return 0;
}
