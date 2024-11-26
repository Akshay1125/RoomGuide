#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    cin.ignore();  // Ignore the newline after the integer input
    while(t--) {
        string s;
        getline(cin, s);  // Read the entire line as input

        int len = 0;  // Length of the longest valid parentheses substring
        int cnt = 0;  // Count of such longest valid parentheses substrings

        stack<int> st;
        st.push(-1);  // Base for the stack to help calculate the length

        for(int i = 0; i < s.length(); i++) {
            if(s[i] == '(') {
                st.push(i);  // Push index of '('
            } else {
                st.pop();  // Pop the top '(' index
                if(!st.empty()) {
                    int currentLen = i - st.top();  // Calculate the length of the valid substring
                    if(currentLen > len) {
                        len = currentLen;  // Update longest length
                        cnt = 1;  // Reset count for this length
                    } else if(currentLen == len) {
                        cnt++;  // Increment count if we find another valid substring of the same length
                    }
                } else {
                    st.push(i);  // Push the current index as a new base for future valid substrings
                }
            }
        }

        if(len == 0) cout << 0 << " " << 1 << endl;  // No valid parentheses
        else cout << len << " " << cnt << endl;  // Output longest length and its count
    }
    return 0;
}
