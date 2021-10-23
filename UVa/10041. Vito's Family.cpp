#include <iostream>
using namespace std;

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int *arr, int front, int end) {
    int i = front - 1, k = arr[end];
    for (int j = front; j < end; j++) {
        if (arr[j] < k) {
            swap(&arr[++i], &arr[j]);
        }
    }
    swap(&arr[++i], &arr[end]);
    return i;
}

void quick_sort(int *arr, int front, int end) {
    if (front < end) {
        int k = partition(arr, front, end);
        quick_sort(arr, front, k - 1);
        quick_sort(arr, k + 1, end);
    }
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int r, s[500], middle, result = 0;
        cin >> r;
        for (int j = 0; j < r; j++) cin >> s[j];
        quick_sort(s, 0, r - 1);
        middle = s[r / 2];
        for (int j = 0; j < r; j++) result += abs(s[j] - middle);
        cout << result << endl;
    }
    return 0;
}