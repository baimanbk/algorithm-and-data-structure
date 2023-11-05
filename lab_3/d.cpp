#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    vector<long long> vectr(n);
    for (int i = 0; i < n; i++) {
        cin >> vectr[i];
    }
    sort(vectr.begin(), vectr.end());
    for (int i = 0; i < q; i++) {
        long long l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        int left1 = lower_bound(vectr.begin(), vectr.end(), l1) - vectr.begin();
        int right1 = upper_bound(vectr.begin(), vectr.end(), r1) - vectr.begin();
        int left2 = lower_bound(vectr.begin(), vectr.end(), l2) - vectr.begin();
        int right2 = upper_bound(vectr.begin(), vectr.end(), r2) - vectr.begin();

        int res = right1 - left1 + right2 - left2;

        for (int j = left1; j < right1; j++) {
            if (vectr[j] >= l2 && vectr[j] <= r2) {
                res--;
            }
        }
        cout << res << '\n';
    }
    return 0;
}
