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
class Solution {
 public:
  ListNode* reverse(ListNode* head, ListNode* last) {
    ListNode *pre, *cur, *next;
    pre = nullptr;
    cur = head;
    while (cur != last) {
      next = cur->next;
      cur->next = pre;
      pre = cur;
      cur = next;
    }
    return pre;
  }
  ListNode* reverseKGroup(ListNode* head, int k) {
    if (head == nullptr) return nullptr;
    ListNode *a, *b;
    a = head;
    b = head;
    for (int i = 0; i < k; i++) {
      if (b == nullptr) return head;
      b = b->next;
    }
    ListNode* newhead = reverse(a, b);
    a->next = reverseKGroup(b, k);
    return newhead;
  }
};