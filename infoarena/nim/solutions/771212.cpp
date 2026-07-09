#include <stdio.h>

using namespace std;

void print_(int s) {
    if (s == 0) {
        printf("NU\n");         
    } else {
        printf("DA\n");       
    }
}

void read_() {
    int n, a;
    scanf("%d", &n);
    int s = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a);
        s = s ^ a;
    } 
    print_(s);
}

int main() {
    freopen("nim.in", "r", stdin);
    freopen("nim.out", "w", stdout);
    
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        read_();
    }
    
    return 0;
}
