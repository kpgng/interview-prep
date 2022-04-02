// Sliding window, expand when able, contract when more than k flips

// Time: O(n)
// Space: O(1)

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i = 0;
        int j = 0;
        
        int result = 0;
        
        while (j < nums.size()) {
            if (nums[j] == 0) {
                k--;
            }
            
            if (k < 0) {
                if (nums[i] == 0) {
                    k++;
                }
                i++;
            }
            
            result = max(result, j - i + 1);
            j++;
        }
        
        return result;
    }
};
