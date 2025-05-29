/*
 * @lc app=leetcode.cn id=142 lang=cpp
 *
 * [142] 环形链表 II
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct ListNode 
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// #include <unordered_set>
// using std::unordered_set;

/**
 * 有个隐藏的已知条件，就是慢指针是不可能走完了完整的一圈的；
 * 快指针一定每次都比慢指针多走一步，不管环长为多少，那么当慢指针走到环内的时候，不管快指针此时在哪个位置，肯定会在慢指针离开圈内前追上慢指针。
 * 慢指针跑一圈，快指针跑两圈。
 * 假设，到入口点的距离为 a， 从入口到相遇点的距离为 b， 慢指针走的距离为 c， 环长为 q
 * 则有， c = a + b;   2c = c + nq (假设走了n圈);
 * 则有 a + b = nq ；能得出， 慢指针走的 a + b 一定是，圈数的倍数
 * 现在慢指针已经在圈里，走了 b ，那么只需要再走a，就一定到了入口。
 */

class Solution 
{
public:
    ListNode *detectCycle(ListNode *head) 
    {
        ListNode* slow = head;
        ListNode* fast = head;

        while( fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if( slow == fast )
            {
                while( slow != head )
                {
                    slow = slow->next;
                    head = head->next;

                }
                return slow;
            }
        }
        return nullptr;

        // 遍历链表，如果出现重复，那一定是在环的入口
        // unordered_set<ListNode*> mark;
        // while(head!=nullptr)
        // {
        //     if( mark.count(head))
        //     {
        //         return head;
        //     }
        //     mark.insert(head);
        //     head = head->next;
        // }
        // return nullptr;
    }
};
// @lc code=end

