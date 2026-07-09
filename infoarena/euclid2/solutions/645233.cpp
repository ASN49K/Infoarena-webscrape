#include<cstdio>

int cmmdc( int a, int b ){
  
  if( a == b ){
    return a;
  } else if( a > b ){
    return( a % b, b );
  } else {
    return( a, b % a );
  }
  
}

int main(){
  
  int i,n,a,b;
  
  freopen( "euclid2.in", "r", stdin );
  freopen( "euclid2.out", "w", stdout );
  
  scanf( "%d", &n );
  
  for( i=0; i<n; ++i ){
    scanf( "%d %d", &a, &b );
    printf( "%d\n", cmmdc( a, b ) );
  }
  
  return 0;
}
