#include <iostream>
#include <climits>
using namespace std;


int Find_Max_Crossing_Subarray(int A[], int low, int mid, int high) {
    int left_sum = INT_MIN;
    int sum = 0;
    for (int i = mid; i >= low; i--) {
        sum += A[i];
        if (sum > left_sum)
            left_sum = sum;
    }

    int right_sum = INT_MIN;
    sum = 0;
    for (int j = mid + 1; j <= high; j++) {
        sum += A[j];
        if (sum > right_sum)
            right_sum = sum;
    }

    return left_sum + right_sum;
}


int Find_Maximum_Subarray(int A[], int low, int high) {
    if (low == high) {
        return A[low]; 
    }

    int mid = (low + high) / 2;

    
    int left_sum = Find_Maximum_Subarray(A, low, mid);
    int right_sum = Find_Maximum_Subarray(A, mid + 1, high);
    int cross_sum = Find_Max_Crossing_Subarray(A, low, mid, high);

    
    if (left_sum >= right_sum && left_sum >= cross_sum)
        return left_sum;
    else if (right_sum >= left_sum && right_sum >= cross_sum)
        return right_sum;
    else
        return cross_sum;
}


int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    int A[n];
    cout << "Enter the array elements: ";
    for (int i = 0; i < n; i++)
        cin >> A[i];

    int max_sum = Find_Maximum_Subarray(A, 0, n - 1);
    cout << "Maximum Subarray Sum: " << max_sum << endl;

    return 0;
}