/* 
 * File:   euclid.cpp
 * Author: alex
 *
 * Created on July 3, 2012, 6:31 PM
 */

#include <cstdlib>
#include <stdio.h>
using namespace std;

int euclid(int a, int b)
{
    if(b == 0)
        return a;
    return euclid(b, a % b);
}
/*
 * 
 */
int main(int argc, char** argv) {

    FILE *f, *o;
    f = fopen("euclid2.in", "r");
    o = fopen("euclid2.out", "w");
    int n, a, b;
    fscanf(f, "%d", &n);
    for(int i = 0; i < n; i++)
    {
        fscanf(f, "%d %d\n", &a, &b);
        fprintf(o, "%d\n", euclid(a, b));
    }
    fclose(f);
    fclose(o);
    return 0;
}

