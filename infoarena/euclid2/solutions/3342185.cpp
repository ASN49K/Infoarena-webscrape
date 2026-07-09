#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long teste;
    cin >> teste;

    for(int i = 0; i < teste; i++){

        long long num1, num2;
        cin >> num1 >> num2;

        while(num1 != num2){
            if(num1 > num2){
                num1 -= num2;
            } else {
                num2 -= num1;
            }
        }

        cout << num1 << "\n";
    }

    return 0;
}
