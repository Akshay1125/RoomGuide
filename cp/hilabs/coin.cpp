#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD = 1e9 + 7;

ll take(ll n, ll k, ll m, ll i, ll bi, vector<vector<vector<ll>>>& dp) {
    // Get the remainder for current sum
    ll rem = bi % m;
    
    // Base cases
    if (k == 0) {
        return (rem == 0) ? 1 : 0;
    }
    if (i >= n || k < 0) {
        return 0;
    }
    
    // Check if state already computed
    if (dp[k][i][rem] != -1) {
        return dp[k][i][rem];
    }
    
    // Calculate result for current state
    ll result = 0;
    
    // Don't take current number
    result = take(n, k, m, i + 1, bi, dp) % MOD;
    ll newSum = (bi + i) % m;
    result = (result + take(n, k - 1, m, i + 1, newSum, dp)) % MOD;
    
    // Store and return result
    return dp[k][i][rem] = result;
}

int main() {
    ll n, k, m;
    cin >> n >> k >> m;
    
    // Initialize 3D dp vector with -1
    // dp[remaining_coins][current_position][current_sum_modulo_m]
    vector<vector<vector<ll>>> dp(k + 1, 
                                 vector<vector<ll>>(n + 1, 
                                 vector<ll>(m, -1)));
    
    cout << take(n, k, m, 0, 0, dp) << endl;
    
    return 0;
}