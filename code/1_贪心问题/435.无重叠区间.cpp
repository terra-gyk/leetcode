/*
 * @lc app=leetcode.cn id=435 lang=cpp
 *
 * [435] 无重叠区间
 */

#include <vector>
#include <algorithm>

using std::vector;

// @lc code=start
class Solution 
{
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) 
    {
        std::sort(intervals.begin(),intervals.end(),[](vector<int>& left, vector<int>& right){return left[1] < right[1]; });
        int pre_end = intervals[0][1]; 
        int size = 0;
        for(size_t index = 1; index < intervals.size(); index++)
        {
            if( intervals[index][0] < pre_end )
            {
                size++;
            }
            else
            {
                pre_end = intervals[index][1];
            }
        }
        return size;
    }
};
// @lc code=end

