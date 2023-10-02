#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>countFrequency;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>min_heap;
        for(int num:nums){
            countFrequency[num]++;
        }
       for (auto it = countFrequency.begin(); it != countFrequency.end(); ++it) {
    min_heap.push({it->second, it->first});
    if (min_heap.size() > k) {
        min_heap.pop();
    }
}
 vector<int>res;
            while(k--){
                res.push_back(min_heap.top().second);
                min_heap.pop();
            }
            return res;
    }
};