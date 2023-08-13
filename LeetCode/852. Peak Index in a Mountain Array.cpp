#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int peakIndexInMountainArray(vector<int> &arr) {
        int left = 0, right = arr.size();

        while (left != right) {
            int mid = (left + right) / 2;
            if (arr[mid] > arr[mid + 1])
                right = mid;
            else
                left = mid + 1;
        }
        return left;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    cout << Solution().peakIndexInMountainArray(arr);
    return 0;
}
