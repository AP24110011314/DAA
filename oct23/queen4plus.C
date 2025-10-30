#include <iostream>
#include <vector>
using namespace std;

class NQueens {
private:
    int n;
    vector<vector<string>> solutions;
    bool isSafe(vector<string>& board, int row, int col) {
        
        for (int i = 0; i < col; i++) {
            if (board[row][i] == 'Q') {
                return false;
            }
        }
        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }
        for (int i = row, j = col; i < n && j >= 0; i++, j--) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }
        
        return true;
    }
    void solve(vector<string>& board, int col) {
        
        if (col == n) {
            solutions.push_back(board);
            return;
        }
        for (int row = 0; row < n; row++) {
            if (isSafe(board, row, col)) {
                
                board[row][col] = 'Q';
                
                
                solve(board, col + 1);
                
                
                board[row][col] = '.';
            }
        }
    }

public:
    NQueens(int numQueens) {
        n = numQueens;
    }
    vector<vector<string>> findAllSolutions() {
        
        vector<string> board(n, string(n, '.'));
        
        
        solve(board, 0);
        
        return solutions;
    }
    void printSolutions() {
        cout << "Number of solutions for " << n << " queens: " << solutions.size() << "\n\n";
        
        for (int i = 0; i < solutions.size(); i++) {
            cout << "Solution " << (i + 1) << ":\n";
            for (const string& row : solutions[i]) {
                for (char cell : row) {
                    cout << cell << " ";
                }
                cout << "\n";
            }
            cout << "\n";
        }
    }
};

int main() {
    int n;
    
    cout << "Enter number of queens (4 or more): ";
    cin >> n;
    
    if (n < 4) {
        cout << "Please enter 4 or more queens.\n";
        return 1;
    }
    
    NQueens solver(n);
    solver.findAllSolutions();
    solver.printSolutions();
    
    return 0;
}