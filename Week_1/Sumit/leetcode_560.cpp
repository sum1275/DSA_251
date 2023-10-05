#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count=0;
        int sum=0;
        int n=nums.size();
        unordered_map<int,int>hmap;
        hmap.insert(make_pair(0,1));
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(hmap.find(sum-k)!=hmap.end()){
                count+=hmap[sum-k];
            }
            hmap[sum]++;
        }
        return count;
    }
};