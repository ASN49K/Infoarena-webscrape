#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>

int findLength(int *first, int *second, int first_length, int second_length);
void createLCS(int *first, int *second, int **c, int i, int j);
std::vector<int> lcs;

int main() {
    int *first, *second;
    int n, m;
    int length;
    FILE *input = fopen("cmlsc.in","r");
    FILE *output = fopen("cmlsc.out","w");

    fscanf(input,"%d %d",&n,&m);

    first = (int*)malloc(n * sizeof(int));
    second = (int*)malloc(m * sizeof(int));

    for(int i = 1; i <= n; i++) {
        fscanf(input,"%d",&first[i]);
    }

    for(int j = 1; j <= m; j++) {
        fscanf(input,"%d",&second[j]);
    }

    length = findLength(first,second,n,m);

    fprintf(output,"%d\n",length);
    std::reverse(std::begin(lcs), std::end(lcs));

    for(int i = 0; i < length; i++) {
        fprintf(output,"%d ",lcs[i]);
    }

    lcs.clear();

    return 0;
}

void createLCS(int *first, int *second, int **c, int i, int j) {
    if( (i == 0) || (j == 0)) {
        return;
    } else if (first[i] == second[j]) {
        lcs.push_back(first[i]);
        createLCS(first, second, c, i - 1, j);
    } else if (c[i][j - 1] > c[i - 1][j]) {
        createLCS(first, second, c, i, j - 1);
    } else {
        createLCS(first, second, c, i - 1, j);
    }
}

int findLength(int *first,
               int *second,
               int first_length,
               int second_length) {
    int **c;

    c = (int**)malloc( (first_length + 1) * sizeof(int*));
    for(int i = 0; i <= first_length; i++) {
        c[i] = (int*)malloc( (second_length + 1) * sizeof(int));
    }

    for(int i = 0; i <= first_length; i++) {
        c[i][0] = 0;
    }

    for(int j = 0; j <= second_length; j++) {
        c[0][j] = 0;
    }

    for(int i = 1; i <= first_length; i++) {
        for(int j = 1; j <= second_length; j++) {
            if(first[i] == second[j]) {
                c[i][j] = c[i - 1][j - 1] + 1;
            } else {
                c[i][j] = std::max(c[i - 1][j], c[i][j - 1]);
            }
        }
    }

    createLCS(first, second, c, first_length, second_length);

    return c[first_length][second_length];
}