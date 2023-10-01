#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
void swap(vector<int>&nums,int mid,int high){
    int temp=nums[high];
    nums[high]=nums[mid];
    nums[mid]=temp;
}
    void sortColors(vector<int>& nums) {
        int low=0,mid=0,high=nums.size()-1;
        while(mid<=high){
            if(nums[mid]==0){
                swap(nums,low,mid);
                low++;
                mid++;
            }else if(nums[mid]==1){
                mid++;

            }else{
                swap(nums,mid,high);
                high--;
            }
        }
    }
};