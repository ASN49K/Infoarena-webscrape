#include <algorithm>

using namespace std ;

int n ;
int x, y ;
int a ,b ;
int *p ;

int euclid(int a, int b) {
  if (b==0) 
    return a ;
  return euclid(b,a%b) ;
}

int main() {
  freopen ("euclid2.in","r",stdin) ;
  freopen ("euclid2.out","w",stdout) ;
  
  scanf ("%d" , &n) ;
  for (int i=1 ; i<=n ; ++i) {
    scanf ("%d%d" , &x , &y);  
    printf("%d\n", euclid(x,y) ) ;
  }
  
  return 0;  
}
