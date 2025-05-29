/*
 * @lc app=leetcode.cn id=605 lang=cpp
 *
 * [605] 种花问题
 */

#include <vector>
using std::vector;

// @lc code=start
class Solution 
{
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) 
    {
        flowerbed.insert(flowerbed.begin(),0);
        flowerbed.push_back(0);
        for(size_t index = 1; index < flowerbed.size() - 1; index++)
        {
            if( flowerbed[index-1] == 0 && flowerbed[index] == 0 && flowerbed[index +1] == 0){
                // 这里可以种花，也可以跳过，因为下个位置肯定不能种花
                // flowerbed[index] = 1;
                index++;
                n--;
            }
        }
        return n <= 0;
        // size_t size = flowerbed.size();
        // for(size_t index = 0; index < size; index++ )
        // {
        //     if( (index == 0 || flowerbed[index - 1] == 0) && flowerbed[index] == 0 && ( index == size - 1 || flowerbed[index+1] == 0))
        //     {
        //         n--;
        //         index++;
        //     }
        // }
        
        // return n <= 0;
    }
};
// @lc code=end

