#include <bits/stdc++.h>


using namespace std;

int binarySearch(const vector<int>& competitors, int target) {
    int left = 0;
    int right = competitors.size() - 1;
    int result = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (competitors[mid] <= target) {
            result = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return result;
}

int main() {
    int N, P;
    cin >> N;
    vector<int> competitors(N);

    for (int i = 0; i < N; i++) {
        cin >> competitors[i];
    }

    cin >> P;

    for (int i = 0; i < P; i++) {
        int MarkPower;
        cin >> MarkPower;
        sort(competitors.begin(), competitors.end());
       
        int defeatedCount = binarySearch(competitors, MarkPower);

        int defeatedSum = 0;
        if (defeatedCount != -1) {
            for (int j = 0; j <= defeatedCount; j++) {
                defeatedSum += competitors[j];
            }
        }

        cout << defeatedCount + 1 << " " << defeatedSum << endl;
    }

    return 0;
}
