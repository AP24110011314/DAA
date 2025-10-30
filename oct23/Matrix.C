#include <iostream>
#include <vector>

using namespace std;


vector<vector<int>> addMatrix(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();
    vector<vector<int>> result(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            result[i][j] = A[i][j] + B[i][j];
        }
    }
    return result;
}


vector<vector<int>> subtractMatrix(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();
    vector<vector<int>> result(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            result[i][j] = A[i][j] - B[i][j];
        }
    }
    return result;
}


vector<vector<int>> strassen(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();
    
    
    if (n == 1) {
        return {{A[0][0] * B[0][0]}};
    }
    
    int half = n / 2;
    
    
    vector<vector<int>> a11(half, vector<int>(half));
    vector<vector<int>> a12(half, vector<int>(half));
    vector<vector<int>> a21(half, vector<int>(half));
    vector<vector<int>> a22(half, vector<int>(half));
    
    vector<vector<int>> b11(half, vector<int>(half));
    vector<vector<int>> b12(half, vector<int>(half));
    vector<vector<int>> b21(half, vector<int>(half));
    vector<vector<int>> b22(half, vector<int>(half));
    
    
    for (int i = 0; i < half; i++) {
        for (int j = 0; j < half; j++) {
            a11[i][j] = A[i][j];
            a12[i][j] = A[i][j + half];
            a21[i][j] = A[i + half][j];
            a22[i][j] = A[i + half][j + half];
            
            b11[i][j] = B[i][j];
            b12[i][j] = B[i][j + half];
            b21[i][j] = B[i + half][j];
            b22[i][j] = B[i + half][j + half];
        }
    }
    
    
    auto M1 = strassen(addMatrix(a11, a22), addMatrix(b11, b22));
    auto M2 = strassen(addMatrix(a21, a22), b11);
    auto M3 = strassen(a11, subtractMatrix(b12, b22));
    auto M4 = strassen(a22, subtractMatrix(b21, b11));
    auto M5 = strassen(addMatrix(a11, a12), b22);
    auto M6 = strassen(subtractMatrix(a21, a11), addMatrix(b11, b12));
    auto M7 = strassen(subtractMatrix(a12, a22), addMatrix(b21, b22));
    
    
    auto c11 = addMatrix(subtractMatrix(addMatrix(M1, M4), M5), M7);
    auto c12 = addMatrix(M3, M5);
    auto c21 = addMatrix(M2, M4);
    auto c22 = addMatrix(subtractMatrix(addMatrix(M1, M3), M2), M6);
    
    
    vector<vector<int>> result(n, vector<int>(n));
    for (int i = 0; i < half; i++) {
        for (int j = 0; j < half; j++) {
            result[i][j] = c11[i][j];
            result[i][j + half] = c12[i][j];
            result[i + half][j] = c21[i][j];
            result[i + half][j + half] = c22[i][j];
        }
    }
    
    return result;
}


void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}


vector<vector<int>> createMatrix(int n) {
    vector<vector<int>> matrix(n, vector<int>(n));
    int count = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = count++;
        }
    }
    return matrix;
}

int main() {
    
    vector<vector<int>> A = {{1, 2}, {3, 4}};
    vector<vector<int>> B = {{5, 6}, {7, 8}};
    
    cout << "Matrix A:" << endl;
    printMatrix(A);
    cout << "\nMatrix B:" << endl;
    printMatrix(B);
    
    auto result = strassen(A, B);
    
    cout << "\nResult of Strassen's multiplication:" << endl;
    printMatrix(result);
    
    return 0;
}