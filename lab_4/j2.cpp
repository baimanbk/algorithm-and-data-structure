#include <bits/stdc++.h>

using namespace std;

vector<int> v1;

int main() {
    int n;
    cin >> n;
    int len = pow(2, n) - 1;
    vector<int> v(len);
    for (int i = 0; i < len; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());

    stack<pair<int, int>> st;
    st.push({0, len - 1});

    while (!st.empty()) {
        int l = st.top().first;
        int r = st.top().second;
        st.pop();

        int mid = l + (r - l) / 2;
        v1.push_back(v[mid]);

        if (l < mid) {
            st.push({l, mid - 1});
        }
        if (mid < r) {
            st.push({mid + 1, r});
        }
    }

    for (int i = 0; i < v1.size(); i++) {
        cout << v1[i] << " ";
    }
}