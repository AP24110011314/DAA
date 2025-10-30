#include <iostream>
#include <stack>
using namespace std;


struct Frame {
    int n;
    char src, aux, dest;
};

void hanoiNonRecursive(int n, char source, char auxiliary, char destination) {
    stack<Frame> st;

    
    st.push({n, source, auxiliary, destination});

    while (!st.empty()) {
        Frame top = st.top();
        st.pop();

        if (top.n == 1) {
            
            cout << "Move disk 1 from " << top.src << " to " << top.dest << endl;
        } else {
            
            st.push({top.n - 1, top.aux, top.src, top.dest}); 
            st.push({1, top.src, top.aux, top.dest});        
            st.push({top.n - 1, top.src, top.dest, top.aux}); 
        }
    }
}

int main() {
    int n;
    cout << "Enter number of disks: ";
    cin >> n;

    cout << "Moves for Tower of Hanoi:\n";
    hanoiNonRecursive(n, 'A', 'B', 'C');

    return 0;
}