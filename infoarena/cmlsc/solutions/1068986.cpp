//
//  main.c
//  training
//
//  Created by Bogdan Iordache on 12/27/13.
//  Copyright (c) 2013 Bogdan Iordache. All rights reserved.
//

#include <stdio.h>
#include <fstream>

using namespace std;

#define DEBUG false

#if DEBUG
#include <iostream>
#define INFILE "/Users/biordach/Documents/Xcode Projects/training/training/cmlsc.in"
#define MAXN 13
#define __OUT cout
#else
#define INFILE "cmlsc.in"
#define MAXN 1024
#define OUTFILE "cmlsc.out"
ofstream __OUT(OUTFILE);
#endif


short n, m;
short a[MAXN], b[MAXN];
short x[MAXN][MAXN], tl[MAXN][MAXN], tc[MAXN][MAXN];

void readInput();
void solve();
void printOutput();
short maxim(short, short);
short maxim(short, short, short);


int main(int argc, const char * argv[])
{
    readInput();
    solve();
    printOutput();

#if DEBUG == false
    __OUT.close();
#endif
    
    return 0;
}

void readInput(){
    FILE *f = fopen(INFILE, "r");
    fscanf(f, "%hd %hd", &m, &n);
    for(int i=0; i<m;i++)
        fscanf(f, "%hd", &a[i]);
    for(int i=0; i<n;i++)
        fscanf(f, "%hd", &b[i]);
    
}

void printX(){
#if DEBUG
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            cout<<x[i][j]<<' ';
        cout<<"| ";
        for(int j=0;j<m;j++)
            cout<<tl[i][j]<<' ';
        cout<<"| ";
        for(int j=0;j<m;j++)
            cout<<tc[i][j]<<' ';
        cout<<"| ";
        
        cout<<'\n';
    }
    cout<<"-----------------------------------\n";
#endif
}

void solve(){
    printX();

    for(int i=0;i<m;i++){
        if(b[0] == a[i]){
            x[0][i] = 1;
            tl[0][i] = -1;
            tc[0][i] = -1;
        } else {
            x[0][i] = i >=1 ? x[0][i-1] : 0;
            tl[0][i] = 0;
            tc[0][i] = i-1;
        }
//        x[0][i] = maxim(x[0][i-1], b[0] == a[i]);
    }

    printX();

    for(int i=1;i<n;i++){
        if(b[i] == a[0]){
            x[i][0] = 1;
            tl[i][0] = -1;
            tc[i][0] = -1;
        } else {
            x[i][0] = i >=1 ? x[i-1][0] : 0;
            tl[i][0] = i-1;
            tc[i][0] = 0;
        }
//        x[i][0] = maxim(x[i-1][0], b[i] == a[0]);
    }
    
    
    for(int i=1;i<n;i++){
        printX();
        
        for(int j=1;j<m;j++){
            x[i][j] = maxim(1 * (b[i] == a[j]) + x[i-1][j-1], x[i][j-1], x[i-1][j]);
            if(x[i][j] == 1 * (b[i] == a[j]) + x[i-1][j-1]){
                tl[i][j] = i - 1;
                tc[i][j] = j - 1;
            } else if(x[i][j] == x[i][j-1]){
                tl[i][j] = i;
                tc[i][j] = j-1;
            } else {
                tl[i][j] = i-1;
                tc[i][j] = j;
            }
        }
    }
    
    printX();
}

void rec(int l, int c, int currentValue){
    if(tl[l][c] == -1 || tc[l][c] == -1){
        __OUT<<b[l] <<' ';
        return;
    }
    if(x[l][c] >0){
        rec(tl[l][c], tc[l][c], x[l][c]);
    }
    if(x[l][c] != currentValue){
        __OUT<<b[l+1]<<' ';
    }
}

void printOutput(){
    __OUT<<x[n-1][m-1]<<'\n';
    rec(n-1, m-1, x[n-1][m-1]);
    __OUT<<'\n';
}

short maxim(short a, short b){
    return a>=b ? a : b;
}

short maxim(short a, short b, short c){
    return maxim(maxim(a, b), c);
}
