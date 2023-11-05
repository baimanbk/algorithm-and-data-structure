#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> blockSizes(n);
    vector<int> prefixSum(n);

    for (int i = 0; i < n; ++i) {
        cin >> blockSizes[i];
        if (i == 0) {
            prefixSum[i] = blockSizes[i];
        } else {
            prefixSum[i] = prefixSum[i - 1] + blockSizes[i];
        }
    }

    vector<int> mistakes(m);
    for (int i = 0; i < m; ++i) {
        cin >> mistakes[i];
    }

    for (int i = 0; i < m; ++i) {
        int mistakeLine = mistakes[i];

        int left = 0, right = n - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (prefixSum[mid] >= mistakeLine) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        
        cout << left + 1 << endl; 
    }

    return 0;
}
