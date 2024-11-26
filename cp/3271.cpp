class Solution {
public:
    string stringHash(string s, int k) {
        
        int n = s.size();
        int len = n/k;

        for(int i =0;i<len;i++){

            string temp = substring(s,i*k, i*k + k);
            cout<<temp<<endl;
        }
    }
};