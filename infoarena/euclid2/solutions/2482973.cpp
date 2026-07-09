#include<bits/stdc++.h>
using namespace std;


int t, a, b;

int euclid(int a, int b){

if(b==0){return a;}
else{return euclid(b, a%b);}

}



int main(){

freopen("euclid2.in","r", stdin);
freopen("euclid2.out", "w", stdout);
scanf("%d", &t);
  for(;t; --t){
      scanf("%d", &a, &b);
      if(b>a){swap(a, b);}
      printf("%d\n", euclid(a, b));
      
  }


    return 0;
}