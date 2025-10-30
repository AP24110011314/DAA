#include <iostream>
using namespace std;
void bubbleSort(int arr[], int n) {
    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}


void bucketSort(int arr[], int n) {
    int maxVal = arr[0];
    for(int i = 1; i < n; i++) {
        if(arr[i] > maxVal) maxVal = arr[i];
    }

    int bucketCount = n; 
    int** buckets = new int*[bucketCount];
    int* bucketSizes = new int[bucketCount];

    for(int i = 0; i < bucketCount; i++) {
        buckets[i] = new int[n];   
        bucketSizes[i] = 0;        
    }

    
    for(int i = 0; i < n; i++) {
        int index = (arr[i] * bucketCount) / (maxVal + 1);
        buckets[index][bucketSizes[index]++] = arr[i];
    }

    
    for(int i = 0; i < bucketCount; i++) {
        if(bucketSizes[i] > 0) {
            bubbleSort(buckets[i], bucketSizes[i]);
        }
    }

    
    int k = 0;
    for(int i = 0; i < bucketCount; i++) {
        for(int j = 0; j < bucketSizes[i]; j++) {
            arr[k++] = buckets[i][j];
        }
    }

    
    for(int i = 0; i < bucketCount; i++) {
        delete[] buckets[i];
    }
    delete[] buckets;
    delete[] bucketSizes;
}


int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int* arr = new int[n];
    cout << "Enter elements: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    bucketSort(arr, n);

    cout << "Sorted array: ";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    delete[] arr;
    return 0;
}