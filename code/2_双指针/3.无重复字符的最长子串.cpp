/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */
#include <unordered_set>
#include <string>
using std::string;
using std::unordered_set;
// @lc code=start

class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        unordered_set<char> mark;
        int size = s.size();
        int fast = -1;
        int ret = 0;

        for( int last = 0; last < size; last++ )
        {
            if( last != 0 )
            {
                mark.erase(s[last - 1]);
            }
            // 将无重复的字符添加到set中
            while( fast + 1 < size && !mark.count(s[fast + 1]) )
            {
                mark.insert(s[fast + 1]);
                fast++;
            }
            ret = std::max( ret, fast - last + 1 );
        }
        return ret;
    }
};
// @lc code=end

