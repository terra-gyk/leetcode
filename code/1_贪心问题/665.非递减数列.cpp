/*
 * @lc app=leetcode.cn id=665 lang=cpp
 *
 * [665] 非递减数列
 */
#include <vector>
#include <algorithm>

using std::vector;

// @lc code=start
class Solution 
{
public:
    bool checkPossibility(vector<int>& nums) 
    {
        int size = nums.size();
        int count = 0;
        for( int i = 0; i < size - 1; i++)
        {
            if( nums[i] > nums[i+1] )
            {
                count++;
                if(count > 1)
                {
                    return false;
                }
                // 这里存在递减，且当前的 i + 1 是递减元素
                // 此时，需要考虑是否更新 i + 1 来防止之后的误判
                // 如果 i + 1 >= i - 1, 可以将 i 更新为 i - 1，后续递增，满足条件。
                // 如果 i + 1 < i - 1, 此时，更新 i 无法满足条件，因此必须要更新 i + 1，但因为 i + 1，仍会在下一轮中使用，为了防止误判，此时需要更新 i + 1 为 i，表示需要更新的值，为 i + 1
                if( i > 0 && nums[i + 1] < nums[i - 1])
                {   
                    nums[i + 1] = nums[i];
                }
            }
        }
        return true;
    }
};
// @lc code=end

