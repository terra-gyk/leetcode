/*
 * @lc app=leetcode.cn id=633 lang=cpp
 *
 * [633] 平方数之和
 */
#include <cmath>

// @lc code=start
class Solution 
{
public:
    bool judgeSquareSum(int c) 
    {
        long left = 0;
        long right = static_cast<int>( std::sqrt(static_cast<double>(c)));
        while(left <= right )
        {
            long sum = left * left + right * right;
            if( sum < c)
            {
                left++;
            }
            else if ( sum > c )
            {
                right--;
            }
            else 
            {
                return true;
            }
        }
        return false;
    }
};
// @lc code=end

