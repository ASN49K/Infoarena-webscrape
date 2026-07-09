/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
short n = 1;
short m = 1;

unsigned char alpha[1024];
unsigned char beta[1024];
unsigned char subsecv[1024];
int main()
{
    ifstream myinput;
    ofstream myoutput;
    int i = 0;
    int j = 0;
    int k = 0;
    int maxlen = 0;
    myinput.open("cmlsc.in");
    myinput >> n >> m;
    for(i = 0;i<n;i++){
        myinput >> alpha[i];
    }
    for(i = 0;i<m;i++){
        myinput >> beta[i];
    }
    k = 0;
    for(i = 0;i< n;i++){
        for(j = 0;j < m; j++){
            if(alpha[i]==beta[j]){
                maxlen += 1;
                subsecv[k] = alpha[i];
                k++;
                break;
            }
        }
        
    }
    myinput.close();
    myoutput.open("cmlsc.out");
    myoutput << maxlen << "\n";
    for(i = 0;i < maxlen; i++){
       myoutput << subsecv[i] << " "; 
    }
    myoutput.close();
    return 0;
}


