/*
 * @lc app=leetcode.cn id=455 lang=cpp
 *
 * [455] 分发饼干
 */
#include <vector>
#include <algorithm>

using std::vector;

// @lc code=start
class Solution 
{
public:
    int findContentChildren(vector<int>& g, vector<int>& s) 
    {
        std::sort(g.begin(),g.end());
        std::sort(s.begin(),s.end());
        size_t g_index = 0;
        size_t s_index = 0;
        size_t g_size = g.size();
        size_t s_size = s.size();
        while( g_index < g_size && s_index < s_size)
        {
            if( g[g_index] <= s[s_index]){
                g_index++;
            }
            s_index++;
        }
        return g_index;
    }
};
// @lc code=end

