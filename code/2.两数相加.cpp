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
struct ListNode ;

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy;
        ListNode* cur = &dummy;
        int carry = 0;
        while( l1 || l2 || carry ) {
            if(l1){
                carry += l1->val;
                l1 = l1->next;
            }
            if(l2){
                carry += l2->val;
                l2 = l2->next;
            }
            cur = cur->next = new ListNode(carry % 10);
            carry /= 10;
        }
        return dummy.next;
    }
};

// @lc code=end

