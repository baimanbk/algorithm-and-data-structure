#include <bits/stdc++.h>

using namespace std;

void MergeSortedIntervals(vector<int> &v, int s, int m, int e) {
	
    // temp is used to temporary store the vector obtained by merging
    // elements from [s to m] and [m+1 to e] in v
	vector<int> temp;

	int i, j;
	i = s;
	j = m + 1;

	while (i <= m && j <= e) {

		if (v[i] <= v[j]) {
			temp.push_back(v[i]);
			++i;
		}
		else {
			temp.push_back(v[j]);
			++j;
		}

	}

	while (i <= m) {
		temp.push_back(v[i]);
		++i;
	}

	while (j <= e) {
		temp.push_back(v[j]);
		++j;
	}

	for (int i = s; i <= e; ++i)
		v[i] = temp[i - s];

}

// the MergeSort function
// Sorts the array in the range [s to e] in v using
// merge sort algorithm
void MergeSort(vector<int> &v, int s, int e) {
	if (s < e) {
		int m = (s + e) / 2;
		MergeSort(v, s, m);
		MergeSort(v, m + 1, e);
		MergeSortedIntervals(v, s, m, e);
	}
}

int main(){
    int n;
    cin >> n;
    int m;
    cin >> m;
    vector<int> v(n);
    for(int i = 0 ; i < n ; i++){
        cin >> v[i];
    }
    vector<int> v1(m);
    for(int i = 0; i < m; i++){
        cin >> v1[i];
    }
    vector<int> r;
    MergeSort(v, 0, n-1);
    MergeSort(v1, 0, m-1);
    int i = 0, j = 0;
     while (i < n && j < m) {
        if (v[i] == v1[j]) {
            cout << v[i] << " ";
            i++;
            j++;
        } else if (v1[j] < v[i]) {
            j++;
        } else {
            i++;
        }
    }
}