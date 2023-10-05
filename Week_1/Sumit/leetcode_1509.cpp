#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n=nums.size();
        int minimum=INT_MAX;
        sort(nums.begin(),nums.end());
        if(n<=3){
            return 0;
        }
        for(int i=1;i<=4;i++){
            minimum=min(minimum,abs(nums[n-i]-nums[4-i]));
        }
        return minimum;
    }
};