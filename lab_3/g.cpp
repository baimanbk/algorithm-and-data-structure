#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isPossible(vector<int>& bags, int n, int k, int h) {
    long long totalHours = 0;

    for (int i = 0; i < n; i++) {
        totalHours += (long long)(bags[i] + k - 1) / k;
    }

    return totalHours <= h;
}

int main() {
    int n, h;
    cin >> n >> h;
    
    vector<int> bags(n);

    for (int i = 0; i < n; i++) {
        cin >> bags[i];
    }

    int left = 1;
    int right = *max_element(bags.begin(), bags.end());
    int result = right;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (isPossible(bags, n, mid, h)) {
            result = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    if(result == 0){
        cout << "1";
        return 0;
    }
    cout << result << endl;

    return 0;
}
