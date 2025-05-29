/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 */
#include <string>
using std::string;

/**
 * 使用滑动窗口，先向右滑，找到所有包含 t 的一个子串
 * 然后，找到之后尝试收缩左边界，找到一个最小的子串
 * 需要记录 t 中的元素个数
 * 右滑时，如果找到了 t 中的字符，需要将对应的计数减 1，直到全部找到
 * 左划时，去掉 t 中不存在，或者多余的字符。
 */


// @lc code=start
class Solution 
{
public:
    string minWindow(string s, string t) 
    {
        int m = s.length();
        int ans_left = -1;
        int ans_right = m;
        int cnt[128]{};
        int less = 0;
        for (char c : t) 
        {
            if (cnt[c] == 0) 
            {
                less++; // 有 less 种字母的出现次数 < t 中的字母出现次数
            }
            cnt[c]++;
        }

        int left = 0;
        for (int right = 0; right < m; right++) 
        { // 移动子串右端点
            char c = s[right]; // 右端点字母
            cnt[c]--; // 右端点字母移入子串
            if (cnt[c] == 0) 
            {
                // 原来窗口内 c 的出现次数比 t 的少，现在一样多
                less--;
            }
            while (less == 0) 
            { // 涵盖：所有字母的出现次数都是 >=
                if (right - left < ans_right - ans_left) 
                { // 找到更短的子串
                    ans_left = left; // 记录此时的左右端点
                    ans_right = right;
                }
                char x = s[left]; // 左端点字母
                if (cnt[x] == 0) 
                {
                    // x 移出窗口之前，检查出现次数，
                    // 如果窗口内 x 的出现次数和 t 一样，
                    // 那么 x 移出窗口后，窗口内 x 的出现次数比 t 的少
                    less++;
                }
                cnt[x]++; // 左端点字母移出子串
                left++;
            }
        }
        return ans_left < 0 ? "" : s.substr(ans_left, ans_right - ans_left + 1);
    }
};
// @lc code=end

