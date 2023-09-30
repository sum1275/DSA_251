// https://leetcode.com/problems/kth-largest-element-in-an-array/description/
#include <bits/stdc++.h>
using namespace std;
int findKthLargest(vector<int> &nums, int k)
{
  k = nums.size() - k;
  return quickSelect(nums, 0, nums.size() - 1, k);
}
int quickSelect(vector<int> &nums, int l, int r, int k)
{
  int p = partition(nums, l, r);

  if (p == k)
    return nums[p];
  else if (p < k)
    return quickSelect(nums, p + 1, r, k);
  else
    return quickSelect(nums, l, p - 1, k);
}

int partition(vector<int> &nums, int l, int r)
{
  int pivot = nums[r];
  int p = l;

  for (int i = l; i < r; ++i)
  {
    if (nums[i] <= pivot)
    {
      swap(nums[p], nums[i]);
      p++;
    }
  }

  swap(nums[p], nums[r]);
  return p;
}
// approach 2 using the merge sort
class Solution
{
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

  void mergeSort(vector<int> &nums, int start, int end)
  {
    if (start >= end)
      return;
    int mid = start + (end - start) / 2;
    mergeSort(nums, start, mid);
    mergeSort(nums, mid + 1, end);
    merge(nums, start, mid, end);
  }

  int findKthLargest(vector<int> &nums, int k)
  {
    int n = nums.size();
    if (n == 1)
    {
      return nums[0];
    }
    else
    {
      mergeSort(nums, 0, n - 1);
      return nums[n - k];
    }
  }
};
