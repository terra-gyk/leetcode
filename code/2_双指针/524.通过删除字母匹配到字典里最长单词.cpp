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


// @lc code=start
class Solution 
{
private:
    bool is_str_has_word(string& str,string& word)
    {
        if( word.size() > str.size() )
        {
            return false;
        }

        int s_index = 0;
        for( char& ch : word)
        {
            while( s_index < str.size() && ch != str[s_index] )
            {
                s_index++;
            }

            if( s_index >= str.size())
            {
                return false;
            }
            s_index++;
        }
        return true;
    }
public:
    string findLongestWord(string s, vector<string>& dictionary) 
    {
        std::sort(dictionary.begin(),dictionary.end(),[](string& l,string& r){
            return l.size() == r.size() ? l < r : l.size() > r.size();
        });

        for(string& word : dictionary)
        {
            if( is_str_has_word(s,word))
            {
                return word;
            }
        }
        return "";
    }
};
// @lc code=end

