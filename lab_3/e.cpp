#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k; cin >> n >> k;
    int a[n][4];
    int max_l = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i][0] >> a[i][1] >> a[i][2] >> a[i][3];
        int local_max = *max_element(a[i], a[i]+4);
        if (local_max > max_l)
            max_l = local_max;
    }
    int left = 1, right = max_l, midl, res;
    while (left <= right) {
        midl = left + (right - left)/2;
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            if (midl >= a[i][0] && midl >= a[i][1] && midl >= a[i][2] && midl >= a[i][3])
                cnt++;
        }if (cnt >= k) {
            res = midl;
            right = midl - 1;
        }else {
            left = midl + 1;
        }}cout << res;}