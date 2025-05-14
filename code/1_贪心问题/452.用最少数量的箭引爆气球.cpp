/*
 * @lc app=leetcode.cn id=452 lang=cpp
 *
 * [452] 用最少数量的箭引爆气球
 */
#include <vector>
#include <algorithm>
using std::vector;

// @lc code=start
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) 
    {
        int size = 1;
        std::sort(points.begin(),points.end(),[](vector<int>& left, vector<int>& right){return left[1] < right[1];});
        int pre_end = points[0][1];
        for( auto node : points )
        {
            if( node[0] > pre_end )
            {
                size++;
                pre_end = node[1];
            }

        }
        return size;


        // int size = 1;
        // std::sort(points.begin(),points.end(),[](vector<int>& left, vector<int>& right){return left[0] < right[0];});
        // int pre_end = points[0][1];
        // for(size_t index = 1; index < points.size(); index++)
        // {
        //     // 这里需要更新右边界
        //     if(points[index][1] < pre_end)
        //     {
        //         pre_end = points[index][1];
        //     }
        //     if(points[index][0] > pre_end)
        //     {
        //         size++;
        //         pre_end = points[index][1];
        //     }
        // }
        // return size;
    }
};
// @lc code=end

