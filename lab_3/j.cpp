#include <bits/stdc++.h>
using namespace std;

bool possible(vector<int>& bag, int n, int k, int h) {
    long long totalHours = 0;

    for (int i = 0; i < n; i++) {
        totalHours += (long long)(bag[i] + k - 1) / k;}
    return totalHours <= h;}

int main() {
    int n, h;
    cin >> n >> h;
    vector<int> bag(n);
    for (int i = 0; i < n; i++) {
        cin >> bag[i];
    }
    int l = 1;
    int r = *max_element(bag.begin(), bag.end());
    int res = r;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (possible(bag, n, mid, h)) {
            res = mid;
            r = mid - 1;
        } else {
            l = mid + 1;}}
    cout << res << endl;
    return 0;}
