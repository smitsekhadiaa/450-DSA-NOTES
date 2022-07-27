// // 34. Find First and Last Position of Element in Sorted Array
// // Medium

// // 12225

// // 315

// // Add to List

// // Share
// // Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

// // If target is not found in the array, return [-1, -1].

// // You must write an algorithm with O(log n) runtime complexity.

// // Example 1:

// // Input: nums = [5,7,7,8,8,10], target = 8
// // Output: [3,4]
// // Example 2:

// // Input: nums = [5,7,7,8,8,10], target = 6
// // Output: [-1,-1]
// // Example 3:

// // Input: nums = [], target = 0
// // Output: [-1,-1]

// // Constraints:

// // 0 <= nums.length <= 105
// // -109 <= nums[i] <= 109
// // nums is a non-decreasing array.
// // -109 <= target <= 109
// class Solution {
// public:
//     vector<int> searchRange(vector<int>& nums, int target) {
//         int n=nums.size();
//         int first,last;
//         int flag=0;
//         for(int i=0;i<n;i++){
//             if(nums[i]==target){
//                 flag=1;
//                 first=i;
//                 break;
//             }
//         }
//         reverse(nums.begin(),nums.end());
//         for(int i=0;i<n;i++){
//             if(nums[i]==target){
//                 flag=1;
//                 last=i;
//                 break;
//             }
//         }
//         vector<int> v;
//         if(flag==0){
//             v.push_back(-1);
//             v.push_back(-1);
//             return v;
//         }

//         last=n-last-1;
//         v.push_back(first);
//         v.push_back(last);
//         return v;

//     }
// };