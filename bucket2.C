#include <iostream>
using namespace std;


struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(NULL) {}
};


void insertSorted(Node*& head, int val) {
    Node* newNode = new Node(val);

    
    if (head == NULL || val < head->data) {
        newNode->next = head;
        head = newNode;
        return;
    }

    
    Node* curr = head;
    while (curr->next != NULL && curr->next->data < val) {
        curr = curr->next;
    }

    newNode->next = curr->next;
    curr->next = newNode;
}


void bucketSort(int arr[], int n) {
    int k = n; 

    
    int maxVal = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > maxVal) maxVal = arr[i];
    }

    
    Node** B = new Node*[k];
    for (int i = 0; i < k; i++) {
        B[i] = NULL;
    }

    
    for (int i = 0; i < n; i++) {
        int index = (arr[i] * k) / (maxVal + 1);
        insertSorted(B[index], arr[i]);
    }

    
    int idx = 0;
    for (int i = 0; i < k; i++) {
        Node* curr = B[i];
        while (curr != NULL) {
            arr[idx++] = curr->data;
            curr = curr->next;
        }
    }

   
    for (int i = 0; i < k; i++) {
        Node* curr = B[i];
        while (curr != NULL) {
            Node* temp = curr;
            curr = curr->next;
            delete temp;
        }
    }
    delete[] B;
}


int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int* arr = new int[n];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    bucketSort(arr, n);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    delete[] arr;
    return 0;
}