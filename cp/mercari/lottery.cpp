#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>
using namespace std;

// Function to get prime factorization parity
vector<int> get_prime_parity(int num) {
    vector<int> primes; // Store primes
    vector<int> parity(100, 0); // Store parities (just assuming primes <= 100)
    
    for (int p = 2; p <= sqrt(num); ++p) {
        if (num % p == 0) {
            int count = 0;
            while (num % p == 0) {
                num /= p;
                count++;
            }
            parity[p] = count % 2; // Store parity (odd or even)
        }
    }
    
    if (num > 1) {
        // num itself is a prime
        parity[num] = 1;
    }
    return parity;
}

int countSubarraysPerfectSquare(vector<int>& arr) {
    int n = arr.size();
    
    // Hash map to store prime parity at each prefix
    unordered_map<string, int> prefix_count;
    
    // Identity prefix (all 0's mean a perfect square product subarray)
    string zero_key(100, '0'); 
    prefix_count[zero_key] = 1;
    
    // Total count of perfect square subarrays
    int count = 0;
    
    // Current prime parity
    vector<int> current_parity(100, 0); 
    
    // Traverse through the array
    for (int i = 0; i < n; ++i) {
        // Get parity for current element
        vector<int> num_parity = get_prime_parity(arr[i]);
        
        // Update current parity
        for (int p = 0; p < 100; ++p) {
            current_parity[p] = (current_parity[p] + num_parity[p]) % 2;
        }
        
        // Convert current parity to a string key
        string key = "";
        for (int p = 0; p < 100; ++p) {
            key += (current_parity[p] + '0');
        }
        
        // Check how many times this key has appeared before
        if (prefix_count.find(key) != prefix_count.end()) {
            count += prefix_count[key];
        }
        
        // Increment the count of this key
        prefix_count[key]++;
    }
    
    return count;
}

/*************  ✨ Codeium Command ⭐  *************/
/**
 * Example main function to test the implementation of countSubarraysPerfectSquare
 *
 * Example usage:
 *     vector<int> arr = {2, 3, 6, 4, 6};
 *     cout << countSubarraysPerfectSquare(arr) << endl;
 * Example output:
 *     2
 */
/******  717470da-2f2f-4e6c-ad81-f1ba34d315dc  *******/int main() {
    vector<int> arr = {2, 3, 6, 4, 6};
    cout << countSubarraysPerfectSquare(arr) << endl;
    return 0;
}
