/*
    Climbing stairs, either 1 or 2 steps, distinct ways to reach top
    Ex. n = 2 -> 2 (1 + 1, 2), n = 3 -> 3 (1 + 1 + 1, 1 + 2, 2 + 1)

    Recursion w/ memoization -> DP, why DP? Optimal substructure
    Recurrence relation: dp[i] = dp[i - 1] + dp[i - 2]
    Reach ith step in 2 ways: 1) 1 step from i-1, 2) 2 steps from i-2

    Time: O(n)
    Space: O(1)
*/

// class Solution {
// public:
//     int climbStairs(int n) {
//         vector<int> memo(n + 1);
//         return dfs(0, n, memo);
//     }
// private:
//     int dfs(int i, int n, vector<int>& memo) {
//         if (i > n) {
//             return 0;
//         }
//         if (i == n) {
//             return 1;
//         }
//         if (memo[i] > 0) {
//             return memo[i];
//         }
//         memo[i] = dfs(i + 1, n, memo) + dfs(i + 2, n, memo);
//         return memo[i];
//     }
// };

class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) {
            return 1;
        }
        if (n == 2) {
            return 2;
        }
        
        int first = 1;
        int second = 2;
        
        int result = 0;
        
        for (int i = 2; i < n; i++) {
            result = first + second;
            first = second;
            second = result;
        }
        
        return result;
    }
};
