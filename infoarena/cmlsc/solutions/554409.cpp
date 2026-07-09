#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
#define maxn 1050
#define maxc 260

int N, M;
int A[maxn], B[maxn];
int dyn[maxn][maxn];
vector<int>::iterator it;
vector<int> first[maxc], second[maxc];

int main() {
    FILE *f1=fopen("cmlsc.in", "r"), *f2=fopen("cmlsc.out", "w");
    int i, j;

    fscanf(f1, "%d %d\n", &N, &M);
    for(i=1; i<=N; i++) {
         fscanf(f1, "%d", &A[i]);
         first[ A[i] ].push_back(i);
    }
    for(i=1; i<=M; i++) {
         fscanf(f1, "%d", &B[i]);
         second[ B[i] ].push_back(i);
    }

    for(i=N; i>=1; i--) {
         for(j=M; j>=1; j--) {
              if(A[i] == B[j]) {
                   dyn[i][j] = dyn[i+1][j+1] + 1;
              }
              dyn[i][j] = max(dyn[i][j], dyn[i][j+1]);
              dyn[i][j] = max(dyn[i][j], dyn[i+1][j]);
         }
    }

    fprintf(f2, "%d\n", dyn[1][1]);

    //afisez cel mai mic lexicografic subsir comun
    int val = dyn[1][1], p1 = 0, p2 = 0;
    while(val) {
         for(i=0; i<=256; i++) {
              while(first[i].size()) {
                   it = first[i].begin();
                   if((*it) <= p1) {
                        first[i].erase(it);
                   }
                   else break;
              }
              while(second[i].size()) {
                   it = second[i].begin();
                   if((*it) <= p2) {
                        second[i].erase(it);
                   }
                   else break;
              }

              if(first[i].size() && second[i].size()) {
                   int fst = first[i][0];
                   int sec = second[i][0];
                   if(dyn[fst][sec] == val) {
                        p1 = fst, p2 = sec;
                        val --;
                        fprintf(f2, "%d ", i);

                        break;
                   }
              }
         }
    }

    fclose(f1); fclose(f2);
    return 0;
}
