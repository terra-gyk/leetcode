/*
 * @lc app=leetcode.cn id=406 lang=cpp
 *
 * [406] 根据身高重建队列
 */

#include <vector>
#include <algorithm>

using std::vector;

// @lc code=start
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) 
    {
        // 矮个子先进
        int size = people.size();
        std::sort(people.begin(),people.end(),[](vector<int>& left,vector<int>& right) { 
            return left[0] < right[0] || ( left[0] == right[0] && left[1] > right[1]); 
        });
        vector<vector<int>> ans(size);
        for(const vector<int>& person : people)
        {
            // 当前人的位置，一定是在比他高人数的后一位，之后的位置
            int space = person[1] + 1;
            for(int i = 0; i < size; i++)
            {
                // 确保这个位置没人
                // 如果有人就向后挪一位
                // 同时，因为是从矮到高排序，所以，这里也确保了，前面的位置一定是够高个子的
                if(ans[i].empty())
                {
                    --space;
                    if( !space )
                    {
                        ans[i] = person;
                        break;
                    }
                }
            }
        }
        return ans;


        // 高个子先进
        // std::sort(people.begin(),people.end(),[](vector<int>& left,vector<int>& right) { 
        //     return left[0] > right[0] || ( left[0] == right[0] && left[1] < right[1]); 
        // });
        // vector<vector<int>> ans;
        // // 按身高大小排序，大的在前面，那么身高高的，前面就不可能有人比他身高更高
        // // 后面的人，前面的身高都是比他高的，只需要在 begin 后 + 人数，就能找到位置
        // // 身高比当前高的都已经塞进队列了，因此不会越界
        // for(const vector<int>& person : people)
        // {
        //     ans.insert(ans.begin() + person[1],person);
        // }
        // return ans;
    }
};
// @lc code=end

