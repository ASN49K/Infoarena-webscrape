#include <cstdio>

typedef unsigned int ui;

inline void read(ui &x);
inline void write(ui x);

inline ui gcd(ui a, ui b){
    while(b)b^=a^=b^=a%=b;
    return a;
}

int main(){
    freopen("euclid2.out","w",stdout);
    freopen("euclid2.in","r",stdin);
    
    ui a, b, t;
    read(t);
    
    do{
        read(a); read(b);
        write(gcd(a,b));
    }while(--t);
    
    return 0;
}

inline void read(ui &x){
    register char c = getchar();
    while(c < '0')c = getchar(); x = c^48;
    for(c=getchar(); 47<c && c<58; c=getchar())
        x = (x<<3) + (x<<1) + (c^48);
}

inline void write(ui x){
    char buf[10], *p = buf;
    do{ *p++ = 48 + x%10; x/=10;}while(x);
    do{ putchar(*--p);}while(p>buf);
    putchar('\n');
}
