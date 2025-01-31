#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, S;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i)
        cin >> A[i];
    cin >> S;
    
    for (int i = 0; i < N && S > 0; ++i) {
        int max_val = A[i];
        int max_pos = i;
        int end = min(i + S, N - 1);
        for (int j = i + 1; j <= end; ++j) {
            if (A[j] > max_val) {
                max_val = A[j];
                max_pos = j;
            }
        }
        if (max_pos != i) {
            S -= (max_pos - i);
            for (int j = max_pos; j > i; --j)
                swap(A[j], A[j-1]);
        }
    }
    
    for (int num : A)
        cout << num << " ";
    cout << endl;
    
    return 0;
}