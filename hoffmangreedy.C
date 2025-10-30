#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;


struct Node {
    char ch;         
    int freq;       
    Node* left;      
    Node* right;    

    Node(char c, int f) {
        ch = c;
        freq = f;
        left = right = nullptr;
    }
};


struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq; 
    }
};


void generateCodes(Node* root, string code) {
    if (!root) return;

    
    if (!root->left && !root->right) {
        cout << root->ch << " : " << code << endl;
        return;
    }

    
    generateCodes(root->left, code + "0");

    
    generateCodes(root->right, code + "1");
}


void HuffmanCoding(vector<char>& chars, vector<int>& freqs) {
    priority_queue<Node*, vector<Node*>, Compare> minHeap;

    
    for (size_t i = 0; i < chars.size(); i++) {
        minHeap.push(new Node(chars[i], freqs[i]));
    }

    
    while (minHeap.size() > 1) {
        Node* left = minHeap.top(); minHeap.pop();
        Node* right = minHeap.top(); minHeap.pop();

        Node* newNode = new Node('$', left->freq + right->freq); 
        newNode->left = left;
        newNode->right = right;

        minHeap.push(newNode);
    }

    
    Node* root = minHeap.top();

    
    cout << "Huffman Codes:\n";
    generateCodes(root, "");
}


int main() {
    vector<char> chars = {'a', 'b', 'c', 'd', 'e', 'f'};
    vector<int> freqs = {5, 9, 12, 13, 16, 45};

    HuffmanCoding(chars, freqs);

    return 0;
}