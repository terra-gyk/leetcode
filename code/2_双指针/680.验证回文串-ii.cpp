/*
 * @lc app=leetcode.cn id=680 lang=cpp
 *
 * [680] 验证回文串 II
 */
#include <string>
using std::string;

// @lc code=start
class Solution 
{
private:
    bool is_Palindrome(string& s,int left ,int right)
    {
        while(left < right)
        {
            if( s[left] != s[right])
            {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }

public:
    bool validPalindrome(string s) 
    {
        int left = 0;
        int right = s.size() - 1;

        while( left < right )
        {
            if( s[left] != s[right])
            {
                return is_Palindrome(s, left + 1, right) || is_Palindrome(s, left, right - 1);
            }
            left++;
            right--;
        }
        return true;
    }
};
// @lc code=end
