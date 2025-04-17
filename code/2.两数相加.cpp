/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

struct ListNode;

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy; // 哨兵节点
        ListNode* cur = &dummy;
        int carry = 0; // 进位
        while (l1 || l2 || carry) { // 有一个不是空节点，或者还有进位，就继续迭代
            if (l1) {
                carry += l1->val; // 节点值和进位加在一起
                l1 = l1->next; // 下一个节点
            }
            if (l2) {
                carry += l2->val; // 节点值和进位加在一起
                l2 = l2->next; // 下一个节点
            }  
            cur = cur->next = new ListNode(carry % 10); // 每个节点保存一个数位
            carry /= 10; // 新的进位
        }
        return dummy.next; // 哨兵节点的下一个节点就是头节点
    }
};
// @lc code=end

