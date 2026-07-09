#include <cstdio>
#include <algorithm>
#define Dim (1<<13)

using namespace std;

unsigned n, poz;
char lin[Dim];

inline void cit(unsigned &x){
	x=0;
	while (lin[poz]<'0' || lin[poz]>'9'){
          poz++;
	      if (poz == Dim) fread(lin, 1, Dim, stdin), poz=0;   
    }
	while (lin[poz]>='0' && lin[poz]<='9'){
		x = 10*x+lin[poz++]-'0';     
        if (poz == Dim) fread(lin, 1, Dim, stdin), poz=0; 
	}            
}

inline void scrie(unsigned k){
     char lin[12], *s;
     s=lin+29; s[0]=0;
     do {
        unsigned cat=k/10;
        s--;
        s[0]=k-cat*10+'0';
        k=cat;
     } while (k);
     puts(s);
}

inline void cmmdc(unsigned u, unsigned v){
    if (!u || !v){
       scrie(u|v);
       return;
    }       
    unsigned ushift=0, vshift=0;
    for( ; !(u & 1) ; u >>= 1, ushift++ );
    for( ; !(v & 1) ; v >>= 1, vshift++ ); 
    while (u != v)
         if( u < v ) {     
             for( v -= u, v >>= 1; !(v & 1) ; v >>= 1 );
         } else {
             for( u -= v, u >>= 1; !(u & 1) ; u >>= 1 );
         }
    if (vshift > ushift) vshift = ushift;
    scrie(u << vshift);
}

int main(){
	freopen("euclid2.in", "r", stdin);
	freopen("euclid2.out", "w", stdout);
	cit(n); 
	while (n--){
		unsigned a, b;
		cit(a); cit(b);
		cmmdc(a, b);
	}
}
