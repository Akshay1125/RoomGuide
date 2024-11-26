class Solution {
public:
    void func(int k, vector<int> &satisfaction){

        int n = satisfaction.size();
        int sum=0;
        int i = n-1;
        while(k>=0 && i>=0){
            sum+= k*satisfaction[i];
            k--;
            i--;
        }
        return sum;
    }
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(),satisfaction.end());

        int n = satisfaction.size();
        int maxi = INT_MIN;
        for(int i =n;i>=0;i++){
            maxi = max(maxi, func(i,satisfaction));
        }

        return maxi;
    }
};