#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end()); // Sort the array
        
        int left = 0;
        int right = 1;
        int count = 0;
        
        while (left < nums.size() && right < nums.size()) {
            if (left != right && nums[right] - nums[left] == k) {
                count++;
                left++;
                right++;
                // Skip duplicates for left pointer
                while (left < nums.size() && nums[left] == nums[left - 1]) {
                    left++;
                }
                // Skip duplicates for right pointer
                while (right < nums.size() && nums[right] == nums[right - 1]) {
                    right++;
                }
            } else if (nums[right] - nums[left] < k) {
                right++;
            } else {
                left++;
            }
            // Ensure right is always greater than left
            if (left >= right) {
                right = left + 1;
            }
        }
        
        return count;
    }
};
