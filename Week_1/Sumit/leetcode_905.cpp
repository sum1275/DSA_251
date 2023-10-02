#include<bits/stdc++.h>
using namespace std;
class Solution {
   
public:
 void swap(vector<int>& nums,int left,int right){
        int temp=nums[right];
        nums[right]=nums[left];
        nums[left]=temp;
    }
    vector<int> sortArrayByParity(vector<int>& nums) {
        int lengthArray=nums.size();
        int start=0,end=lengthArray-1;
        while(start<=end){
            if (nums[start] % 2 != 0) {
                if (nums[end] % 2 == 0) {
                    swap(nums, start, end);
                }
                end--;
            } else{
                start++;
            }
        }
        return nums;

    }
};