#include <bits/stdc++.h>
using namespace std;

int main()
{
    string line;
    int nr, temp, x;
    short check, times;
    int divs_1[19] = {0};
    int divs_2[19] = {0};
    temp=0;

    ifstream inputFile("euclid2.in.txt");
    ofstream outputFile("euclid2.out.txt");

    inputFile>>line;
    istringstream strings(line);
    strings>>nr;
    if(nr < 2 || nr > 100000){
        outputFile<<"Mai putine linii puneti in fisier (intre 2 si 100000)";
        inputFile.close();
    outputFile.close();
        exit(0);
    }
    times=nr;

for(int i=0; i<times; i++){
    inputFile>>line;
    istringstream strings2(line);
    strings2>>nr;
    if(nr < 2 || nr > 2*pow(10,9)){
        outputFile<<"Numerele trebuie sa fie intre 2 si 2*10^9";
        inputFile.close();
    outputFile.close();
        exit(0);
    }
    x=11;
    temp=0;
    while(nr!=1){
        if(nr%2==0){
        nr/=2; divs_1[temp]=2; temp++;
        }else if(nr%3==0){
        nr/=3; divs_1[temp]=3; temp++;
        }else if(nr%5==0){
        nr/=5; divs_1[temp]=5; temp++;
        }else if(nr%7==0){
        nr/=7; divs_1[temp]=7; temp++;
        }else{
            if(nr%x==0){nr/=x; divs_1[temp]=x; temp++;}
            else{x++;}

        }
    }


    //next nr

        inputFile>>line;
        istringstream strings3(line);
    strings3>>nr;
        if(nr < 2 || nr > 2*pow(10,9)){
        outputFile<<"Numerele trebuie sa fie intre 2 si 2*10^9";
        inputFile.close();
    outputFile.close();
        exit(0);
    }
    temp=0;
    x=11;
    while(nr!=1){
        if(nr%2==0){
        nr/=2; divs_2[temp]=2; temp++;
        }else if(nr%3==0){
        nr/=3; divs_2[temp]=3; temp++;
        }else if(nr%5==0){
        nr/=5; divs_2[temp]=5; temp++;
        }else if(nr%7==0){
        nr/=7; divs_2[temp]=7; temp++;
        }else{
            if(nr%x==0) {nr/=x; divs_2[temp]=x; temp++;}
            else{x++;}
        }
    }


    //get greatest divider and reusing previous variables
    x=1;
    temp=0;
    check=0;
    for(int k=0; k<19; ++k){
            if(divs_1[k]==divs_2[k] && divs_1[k] != 0  && divs_2[k] != 0){x*=divs_1[k];}
            else if(divs_1[k+temp]<divs_2[k] && divs_1[k+temp] != 0  && divs_2[k] != 0){
                while( divs_1[k+temp] != 0 && check!=1){
                    if(divs_1[k+temp]==divs_2[k] && divs_1[k+temp] != 0  && divs_2[k] != 0){x*=divs_2[k]; check=1;}
                    else{temp++;}
                }
                check=0;
            }
            else if(divs_1[k]>=divs_2[k+temp] && divs_1[k] != 0  && divs_2[k+temp] != 0){
                while(divs_2[k+temp] != 0 && check!=1){
                        if(divs_1[k]==divs_2[k+temp] && divs_1[k] != 0  && divs_2[k+temp] != 0){x*=divs_1[k]; check=1;}
                        else{temp++;}
                }
                check=0;
            }

        }
    outputFile<<x<<endl;

    for(int k=0; k<19; ++k){
        divs_1[k]=0;
        divs_2[k]=0;
    }


}

    inputFile.close();
    outputFile.close();
    return 0;
}
