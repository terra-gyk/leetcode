/*
 * @lc app=leetcode.cn id=8 lang=cpp
 *
 * [8] 字符串转换整数 (atoi)
 */

// @lc code=start

#include <unordered_map>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        int sign = 1;
        long long res = 0;
        string::iterator it = str.begin();
        while( *it == ' '){
            it++;
        }
        if( *it == '-'){
            sign = -1;
        }
        if( *it == '+'){   
        }
        
        while( it != str.end()){
            if( *it < '0' || *it > '9'){
                break;
            }
            res = res * 10 + *it - '0'; 
            res = sign == 1 ? min((long long)INT_MAX,res) : min(-(long long)INT_MIN,res);
            it++;
        }


        return sign * res;
    }
};






// class Automaton {
//     string state = "start";
//     unordered_map<string, vector<string>> table = {
//         {"start", {"start", "signed", "in_number", "end"}},
//         {"signed", {"end", "end", "in_number", "end"}},
//         {"in_number", {"end", "end", "in_number", "end"}},
//         {"end", {"end", "end", "end", "end"}}
//     };

//     int get_col(char c) {
//         if (isspace(c)) return 0;
//         if (c == '+' or c == '-') return 1;
//         if (isdigit(c)) return 2;
//         return 3;
//     }
// public:
//     int sign = 1;
//     long long ans = 0;

//     void get(char c) {
//         state = table[state][get_col(c)];
//         if (state == "in_number") {
//             ans = ans * 10 + c - '0';
//             ans = sign == 1 ? min(ans, (long long)INT_MAX) : min(ans, -(long long)INT_MIN);
//         }
//         else if (state == "signed")
//             sign = c == '+' ? 1 : -1;
//     }
// };

// class Solution {
// public:
//     int myAtoi(string str) {
//         Automaton automaton;
//         for (char c : str)
//             automaton.get(c);
//         return automaton.sign * automaton.ans;
//     }
// };

// @lc code=end

