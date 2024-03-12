#include<bits/stdc++.h>
using namespace std;
bool isPossible(const vector<int>& stalls, int k, int mid) {
    int cows = 1;
    int lastCowPosition = stalls[0];
    for (int i = 1; i < stalls.size(); ++i) {
        if (stalls[i] - lastCowPosition >= mid) {
            ++cows;
            lastCowPosition = stalls[i];
            if (cows >= k)
                return true;
        }
    }
    return false;
}
int aggressiveCows(const vector<int>& stalls, int k) {
    sort(stalls.begin(), stalls.end());
    int s = 0;
    int e = stalls.back();
    int ans = -1;
    while (s <= e) {
        int mid = s + (e - s) / 2;
        if (isPossible(stalls, k, mid)) {
            ans = mid;
            s = mid + 1;
        } else {
            e = mid - 1;
        }
    }
    return ans;
}
int main() {
    int n, k;
    cin >> n >> k;
    cout<<"Enter the array: ";
    vector<int> stalls(n);
    for (int i = 0; i < n; ++i){
          cin >> stalls[i];
    }
    cout << "Maximum subarray size: " << aggressiveCows(stalls, k) << endl;
    return 0;
}
