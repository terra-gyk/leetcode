/*
 * @lc app=leetcode.cn id=524 lang=cpp
 * 
 * [524] 通过删除字母匹配到字典里最长单词
 */

#include <algorithm>
#include <vector>
#include <string>
using std::vector;
using std::string;

class Solution {
public:
    bool isSubsequence(string& s, string& w) 
    {
        int s_size = s.size();
        int w_size = w.size();
        if( w_size > s_size )
        {
            return false;
        }

        int index = 0;
        for(char& ch : w)
        {
            while( index < s_size && ch != s[index] )
            {
                index++;
            }
            if( index >= s_size )
            {
                return false;
            }
            index++;
        }
        return "";
    }

    string findLongestWord(string s, vector<string>& dictionary) 
    {
        // 更长的、字典序更小的排在前面，这样一旦找到，就是结果
        std::sort(dictionary.begin(),dictionary.end(),[](string& left,string& right){
           return left.size() == right.size() ? left < right : left.size() > right.size(); 
        });
        
        for(string& word : dictionary)
        {
            if( isSubsequence(s, word) )
            {
                return word;
            }
        }
        return "";
    }
};

// @lc code=end

