#include <cstdio>
using namespace std;

inline int euclid(int a, int b) {
    int c;
    while(b) {
        c=a%b;
        a=b;
        b=c;
    }
    return a;
}

int main(void) {
    FILE *fi = fopen("euclid.in", "r");
    FILE *fo = fopen("euclid.out", "w");
    int n, a, b;

    fscanf(fi,"%d",&n);
    while(n--) {
        fscanf  (fi,"%d%d",&a,&b);
        fprintf (fo,"%d\n",euclid(a, b));
    }
    return 0;
}
