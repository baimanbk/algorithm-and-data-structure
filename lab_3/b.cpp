#include <bits/stdc++.h>

using namespace std;

bool isPossible(vector<long long>& blocks, long long n, long long m, long long mid) {
    long long ghouls = 0;
    long long currentSum = 0;

    for (long long i = 0; i < n; i++) {
        if (blocks[i] > mid) {
            return false;
        }
        if (currentSum + blocks[i] <= mid) {
            currentSum += blocks[i];
        } else {
            ghouls++;
            currentSum = blocks[i];
        }
    }

    return (ghouls < m);
}

int main() {
    long long n, m;
    cin >> n >> m;

    vector<long long> blocks(n);
    long long maxBlock = 0;

    for (long long i = 0; i < n; i++) {
        cin >> blocks[i];
        maxBlock = max(maxBlock, blocks[i]);
    }

    long long l = maxBlock;
    long long r = 1e14;
    long long result = -1;

    while  (l <= r) {
        long long mid = l + (r - l) / 2;
        if (isPossible(blocks, n, m, mid)) {
            result = mid;
            r = mid - 1;
        } else {
         l = mid + 1;
        }
    }
    cout << result << endl;
    return 0;
}
