/* 
 * File:   main.cpp
 * Author: manuel
 *
 * Created on October 28, 2011, 8:33 PM
 */

#include <fstream>

using namespace std;

int gcd(int a, int b){
    if (!b)
        return a;
    gcd(b, a % b);
}


    

int main(int argc, char** argv) {
    int numberOfPairs;
//    ifstream inputFile;
//    ofstream outputFile;
//    inputFile.open("euclid2.in");
    
//    outputFile.open ("euclid2.out");
//    inputFile >> numberOfPairs;
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);
    scanf("%d", &numberOfPairs);
    int a, b;
    while (numberOfPairs--){
//        inputFile >> a;
//        inputFile >> b;
//        outputFile<<gcd(a, b)<<endl;
        scanf("%d %d", &a, &b);
        printf("%d\n", gcd(a, b));
    }
//    inputFile.close();
//    outputFile.close();
    return 0;
}