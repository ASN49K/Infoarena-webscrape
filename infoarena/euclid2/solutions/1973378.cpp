#include <iostream>
#include <fstream>
#include <vector>
#define MAX 100000

using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");

int N,K,a,b,first[MAX],second[MAX];


int cmmdc(int a , int b){
    if(b == 0){
        return a;
    }else if(a == 0){
        return b;
    }
    else{
        return cmmdc(b,a%b);
    }
}

int main()
{
    in>>K;
    for(int i = 1; i <= K; i++){
        in>>a>>b;
        first[i] = a;

        second[i] = b;

    }


   for(int i = 1; i <=K; i ++){
        out<<cmmdc(first[i],second[i])<<endl;
   }




    return 0;
}

