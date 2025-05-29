/*
 * @lc app=leetcode.cn id=763 lang=cpp
 *
 * [763] 划分字母区间
 */
#include <vector>
#include <string>

using std::vector;
using std::string;

// @lc code=start
class Solution 
{
public:
    vector<int> partitionLabels(string s) 
    {
        int end_index[256];
        int size = s.size();
        for(int index = 0; index < size; index++)
        {
            end_index[s[index] - 'a'] = index;
        }
        vector<int> partition;
        int start = 0, end = 0;
        for( int index = 0; index < size; index++ )
        {
            end = std::max(end,end_index[s[index] - 'a']);
            // 上面的 end 取最大，保证了， end 是前面所有 end 中最大的
            // 这里就是筛选，说明这个 end 已经能包含前面所有的字符了。
            if(end == index)
            {
                partition.push_back( end - start + 1);
                start = end + 1;
            }
        }
        return partition;
    }
};
// @lc code=end

