/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

#include <vector>
#include <unordered_map>
using std::vector;

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int,int> mark;
        for(int index = 0; index < nums.size(); index++ )
        {
            auto iter = mark.find(target - nums[index]);
            if(iter != mark.end()){
                return {iter->second,index};
            }
            mark[nums[index]] = index;
        }
        return {};
    }
};
// @lc code=end

