#include<bits/stdc++.h>
using namespace std;
class Solution {
  public: int longestConsecutive(vector < int > & nums) {
    int n = nums.size();
    unordered_map < int, bool > umap;
    for (int i = 0; i < n; i++) {
      umap[nums[i]] = true;
    }
    for (int val: nums) {
      if (umap.find(val - 1) != umap.end()) {
        umap[val] = false;
      }
    }
    int msp = 0, ml = 0; //msp=maximum starting point ,ml=maxximum length
    for (int val: nums) {
      if (umap.find(val) != umap.end() && umap[val] == true) {
        int tl = 0, tsp = val;
        while (umap.find(tsp + tl) != umap.end()) {
          tl++;
        }
        if (tl > ml) {
          msp = tsp;
          ml = tl;
        }
      }
    }
    return ml;

  }
};