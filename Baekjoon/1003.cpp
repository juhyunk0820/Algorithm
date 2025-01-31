#include <iostream>
using namespace std;

int main() {
    int T, N;
    int zero[41] = {0};
    int one[41] = {0};
    
    zero[0] = 1;
    one[1] = 1;
    
    for(int i=2; i<=40; ++i){
        zero[i] = zero[i-1] + zero[i-2];
        one[i] = one[i-1] + one[i-2];
    }
    
    cin >> T;
    while(T--){
        cin >> N;
        cout << zero[N] << " " << one[N] << '\n';
    }
    
    return 0;
}