/*
 * @lc app=leetcode.cn id=135 lang=cpp
 *
 * [135] 分发糖果
 */

#include <vector>
#include <numeric>
using std::vector;

// @lc code=start
class Solution 
{
public:
    int candy(vector<int>& ratings) 
    {
        size_t size = ratings.size();
        vector<int> candy(size,1);
        for(size_t index = 1; index < size; index++)
        {
            if(ratings[index] > ratings[index-1])
            {
                candy[index] = candy[index - 1] + 1;
            }
        }

        for(size_t index = size - 1; index > 0; index--)
        {
            if(ratings[index] < ratings[index - 1])
            {
                candy[index-1] = std::max(candy[index-1],candy[index]+1);
            }

        }
        return std::accumulate(candy.begin(),candy.end(),0);
    }
};
// @lc code=end

