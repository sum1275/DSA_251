#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
  int findMaxLength(vector<int>& nums) {
    int ans = 0;
    unordered_map<int, int> hmap;
    int sum = 0;
    int len = nums.size();
    hmap.insert(make_pair(0, -1));

    for (int i = 0; i < len; i++) {
        if (nums[i] == 0) {
            sum += -1;
        } else if (nums[i] == 1) {
            sum += 1;
        }

        if (hmap.find(sum) != hmap.end()) {
            int length = i - hmap[sum];
            ans = max(ans, length);
        } else {
            hmap[sum] = i;
        }
    }

    return ans;
}

};