#include<bits/stdc++.h>
using namespace std;
class Solution {
  public: vector < vector < int >> kSmallestPairs(vector < int > & nums1, vector < int > & nums2, int k) {
    vector < vector < int >> result;
    priority_queue < pair < int, pair < int, int >>> maxHeap;

    for (int i = 0; i < nums1.size(); i++) {
      for (int j = 0; j < nums2.size(); j++) {
        if (maxHeap.size() < k) {
          maxHeap.push({
            nums1[i] + nums2[j],
            {
              nums1[i],
              nums2[j]
            }
          });
        } else {
          if (nums1[i] + nums2[j] < maxHeap.top().first) {
            maxHeap.pop();
            maxHeap.push({
              nums1[i] + nums2[j],
              {
                nums1[i],
                nums2[j]
              }
            });
          } else if (nums1[i] + nums2[j] > maxHeap.top().first) {
            break;
          }
        }
      }
    }

    while (!maxHeap.empty()) {
      result.push_back({
        maxHeap.top().second.first,
        maxHeap.top().second.second
      });
      maxHeap.pop();
    }

    return result;

  }
};