#include <fstream>
#include <algorithm>
#define dim 100010
using namespace std;
char a[dim];
int i,x,nr;

int expresie();
int expresie1();
int expresie2();
int factor();

int main() {
    ifstream fin("expresie7.in");
    ofstream fout("expresie7.out");
    fin>>a;
    i=0;
    x=expresie();
    fout<<nr<<"\n"<<x;
    return 0;
}

int expresie() {
    int r=factor();
    while (a[i]==',') {
        i++;
        int m=factor();
        r+=m;
    }
    return r;
}

int factor() {
    int r=0;
    int ok=1;
    if (isdigit(a[i])||a[i]=='-') {
        if (a[i]=='-') {
            i++;
            ok=-1;
        }
        while (isdigit(a[i])) {
            r=r*10+a[i]-'0';
            i++;
        }
        r*=ok;
        nr++;
    }
    else if (a[i]=='(') {
        i++;
        r=expresie1();
        i++;
    }
    else if (a[i]=='[') {
        i++;
        r=expresie2();
        i++;
    }
    return r;
}

int expresie1() {
    int v[dim];
    int n=0;
    v[++n]=factor();
    while (a[i]==',') {
        i++;
        v[++n]=factor();
    }
    int d=v[1];
    int Max=d;
    for (int j=2;j<=n;j++) {
        if (v[j]+d>v[j]) {
            d+=v[j];
        }
        else {
            d=v[j];
        }
        Max=max(Max,d);
    }
    return Max;
}

int expresie2() {
    int v[dim];
    int n=0;
    v[++n]=factor();
    while (a[i]==',') {
        i++;
        v[++n]=factor();
    }
    sort(v+1,v+n+1);
    return v[(n+1)/2];
}
