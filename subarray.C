#include <iostream>
#include <climits>   
using namespace std;

void MaxSubarray_BruteForce(int A[], int n) {
    int max_sum = INT_MIN; 
    int end_index = 0;
    int start_index=0;

    for (int i = 0; i < n; i++) {
        int current_sum = 0;
        for (int j = i; j < n; j++) {
            current_sum += A[j];

            if (current_sum > max_sum) {
                max_sum = current_sum;
                start_index = i;
                end_index = j;
            }
        }
    }

    cout << "Maximum Subarray Sum: " << max_sum << endl;
    cout << "Starting Index: " << start_index << endl;
    cout << "Ending Index: " << end_index << endl;
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    int A[n];
    cout << "Enter the array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    MaxSubarray_BruteForce(A, n);
    return 0;
}