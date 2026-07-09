#include<bits/stdc++.h>
using namespace std;
ifstream fin("euclid2.in");ofstream fout("euclid2.out"); 

int t, a, b;

int euclid(int a, int b){

if(b==0){return a;}
else{return euclid(b, a%b);}

}



int main(){

fin>>t;

  for(int i=0; i<t; i++){
      fin>>a>>b;
      cin>>a>>b;
      if(b>a){swap(a, b);}
      fout<<euclid(a, b)<<endl;
      
  }


    return 0;
}