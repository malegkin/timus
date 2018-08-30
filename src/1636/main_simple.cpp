#include<iostream>
using namespace std;
int main(){
    int n, k, t, sum = 0, time;
    cin >> n;
    cin >> k;
    for(int i = 0; i<10; i++){
        cin >> t;
        sum += t;
    }
    time = sum * 20;
    if( k - time >= n) cout << "No chance.";
    else if(k - time < n) cout << "Dirty debug :(";

}