
#include <fstream>
#include <algorithm>
#include <stack>
#define MaxNumberOfLetters 1025
using namespace std;

ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");

int arr1[MaxNumberOfLetters], arr2[MaxNumberOfLetters];
int lg1, lg2;
stack <int> Stack;
int dp[MaxNumberOfLetters][MaxNumberOfLetters];

int main()
{
    cin >> lg1 >> lg2;
    for(int i = 1; i <= lg1; i++){
        cin >> arr1[i];
    }
    for(int i = 1; i <= lg2; i++){
        cin >> arr2[i];
    }                                   
    for(int i = 1; i <= lg1; i++){
        for(int j = 1; j <= lg2; j++){
            if(arr1[i] == arr2[j]){
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else{
                dp[i][j] = max(dp[i - 1][j],dp[i][j - 1]);
            }
        }
    }
    cout << dp[lg1][lg2] << "\n";
    int index1 = lg1, index2 = lg2;
    while(index1 >= 1 && index2 >= 1){
        if(arr1[index1] == arr2[index2]){
            Stack.push(arr1[index1]);
            --index1;
            --index2;
        }
        else{
            if(dp[index1][index2] == dp[index1 - 1][index2]){
                index1--;
            }
            else{
                index2--;
            }
        }
    }
    while(!Stack.empty()){
        cout << Stack.top() << " ";
        Stack.pop();
    }
    return 0;
}