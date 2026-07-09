#include<iostream>

using namespace std;

int main () {
    int dim;
    cout << "dimensiune array: ";
    cin >>  dim;
    int a[dim] = {0};
    int n, tail = 0;
    int head = 0;
    cout << "introdu operatiunea, (1/2/0): " << endl;
    cin >> n;
    int nr = 0;
    while(n != 0) {
        if (nr > dim - 2) {
            cout << "trebe sa scoti" << endl;
        }
        if (n == 1 && nr <= dim - 2) {
            cout << "baga in coada: ";
            cin >> a[tail];
            tail++;
            nr++;
        } 
        if (n == 2) {
            cout << "scot din coada: " << a[head] << endl;
            a[head] = 0;
            head++;
            nr--;
        }
        if (head == dim) {
            head = 0;
        }
        if (tail ==  dim) {
            tail = 0;
        }
        
        cout << "introdu operatiunea, (1/2/0): " << endl;
        cin >> n;
    }
}