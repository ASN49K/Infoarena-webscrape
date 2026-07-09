#include <iostream>
#include <fstream>

using namespace std;
int i,j, v1[1024], v2[1024], M, N, maxim, aux[1024],k;
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

void citire(int n, int arr[1024]){
    for(i = 0;i < n; i++){
        in>>arr[i];
    }
}

void comparare(int n, int m, int arr1[1024], int arr2[1024]){
    int okUnic,i,j;
    for(i=0;i<m;i++){
        okUnic = 0;
        for(j=0;j<n;j++){
            if(arr1[i] == arr2[j] && okUnic == 0){
                aux[k] = arr1[i];
                maxim++;
                okUnic = 1;
                k++;
            }
        }
    }
}

void afisare(int k){
    int i;
    for(i=0;i<k;i++){
        out<<aux[i]<<" ";
    }
}

int main()
{
    in>>M>>N;
    citire(M, v1);
    citire(N, v2);
    comparare(N, M, v1, v2);
    out<<maxim<<endl;
    afisare(k);

}
