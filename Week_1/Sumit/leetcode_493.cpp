#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
 void merge(vector<int> &nums, int left, int mid, int right)
  {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    vector<int> leftArr(n1);
    vector<int> rightArr(n2);

    for (int i = 0; i < n1; i++)
      leftArr[i] = nums[left + i];

    for (int i = 0; i < n2; i++)
      rightArr[i] = nums[mid + 1 + i];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2)
    {
      if (leftArr[i] <= rightArr[j])
      {
        nums[k] = leftArr[i];
        i++;
      }
      else
      {
        nums[k] = rightArr[j];
        j++;
      }
      k++;
    }

    while (i < n1)
    {
      nums[k] = leftArr[i];
      i++;
      k++;
    }

    while (j < n2)
    {
      nums[k] = rightArr[j];
      j++;
      k++;
    }
  }
int countPairs(vector<int>&nums,int start,int mid,int end){
    int right=mid+1;
    int count=0;
    long num=0;
    for(int i=start;i<=mid;i++){
        while(right<=end && nums[right] <= nums[i] / 2)
        right++;
        count+=(right-(mid+1));

    }
    return count;
}
  int mergeSort(vector<int> &nums, int start, int end)
  { int count=0;
    if (start >= end)
      return count;
    int mid = start + (end - start) / 2;
    count+=mergeSort(nums, start, mid);
    count+=mergeSort(nums, mid + 1, end);
    count+=countPairs(nums,start,mid,end);
    merge(nums, start, mid, end);
    return count;
  }

    int reversePairs(vector<int>& nums) {
        int n=nums.size();
        return mergeSort(nums,0,n-1);
    }
};