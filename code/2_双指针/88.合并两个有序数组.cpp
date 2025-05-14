/*
 * @lc app=leetcode.cn id=88 lang=cpp
 *
 * [88] 合并两个有序数组
 */
#include <vector>
using std::vector;

// @lc code=start
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
    {
        int left = m - 1;
        int right = n -1;
        int index = m + n -1;
        while( left >= 0 || right >= 0 )
        {
            int cur = 0;
            if( left < 0 )
            {
                cur = nums2[right--];
            }
            else if ( right < 0 )
            {
                cur = nums1[left--];
            }
            else if( nums1[left] < nums2[right] )
            {
                cur = nums2[right--];
            }
            else 
            {
                cur = nums1[left--];
            }
            nums1[index--]=cur;
        }
    }
};
// @lc code=end

