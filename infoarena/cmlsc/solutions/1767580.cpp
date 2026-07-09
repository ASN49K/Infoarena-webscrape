/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   cmlsc.cpp
 * Author: daniel
 *
 * Created on 29 September 2016, 11:59
 */

#include <cstdlib>
#include <cstdio>

using namespace std;

const int MAX_NM = 1005;
int m[MAX_NM], n[MAX_NM];
int d[MAX_NM][MAX_NM];
int results[MAX_NM];

int max3(int a, int b, int c) {
   if(a >= b && a >= c) {
       return a;
   }
   else if(b >= a && b >= c) {
       return b;
   }
   return c;
}

/*
 * 
 */
int main(int argc, char** argv) {
    FILE *fin = fopen("cmlsc.in", "r");
    FILE *fout = fopen("cmlsc.out", "w");

    int M, N;
    
    fscanf(fin, "%d %d", &M, &N);
    
    for(int i = 1 ; i <= M ; i++) {
        fscanf(fin, "%d", &m[i]);
    }
    
    for(int i = 1 ; i <= N ; i++) {
        fscanf(fin, "%d", &n[i]);
    }
    
    for(int i = 1 ; i <= M ; i++) {
        for(int j = 1 ; j <= N ; j++) {
            int previous = d[i - 1][j - 1];
            if(m[i] == n[j]) {
                previous += 1;
//                printf("i: %d, j: %d", i, j);
            }
            d[i][j] = max3(d[i - 1][j], d[i][j - 1], previous);
        }
    }
    
//    for(int i = 1 ; i <= M ; i++) {
//        for(int j = 1 ; j <= N ; j++) {
//            fprintf(fout, "%d ", d[i][j]);
//        }
//        fprintf(fout, "\n");
//    }
//    fprintf(fout, "%d", d[M][N]);
    
    int i = M, j = N;
    while(i > 1 || j > 1) {
        if(d[i][j] == d[i - 1][j - 1] + 1 && m[i] == n[j]) {
            results[++results[0]] = m[i];
            i -= 1;
            j -= 1;
        }
        else if(i > 1 && d[i][j] == d[i - 1][j]) {
            i -= 1;
        }
        else {
            j -=1;
        }
    }
    
    fprintf(fout, "%d\n", results[0]);
            
    for(int i = results[0] ; i > 0 ; i--) {
        fprintf(fout, "%d ", results[i]);
    }
    
    fclose(fin);
    fclose(fout);

    return 0;
}

