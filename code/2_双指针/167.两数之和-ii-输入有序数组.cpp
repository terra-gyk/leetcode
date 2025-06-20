/*
 * @lc app=leetcode.cn id=167 lang=cpp
 *
 * [167] 两数之和 II - 输入有序数组
 */
#include <vector>

using std::vector;

// @lc code=start
class Solution 
{
public:
    vector<int> twoSum(vector<int>& numbers, int target) 
    {
        int left = 0;
        int right = numbers.size() - 1;

        while ( left < right )
        {
            int sum = numbers[left] + numbers[right];
            if( sum == target )
            {
                break;
            }
            if( sum < target )
            {
                left++;
            }
            else
            {
                right--;
            }
        }
        return {left+1,right+1};
    }
};
// @lc code=end

