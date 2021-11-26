ListNode left;

boolean isPalindrome(ListNode head) {
  left = head;
  return traverse(head);
}

boolean traverse(ListNode right) {
  if (right == null) return true;
  boolean res = traverse(right.next);
  // 后序遍历代码
  res = res && (right.val == left.val);
  left = left.next;
  return res;
}

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
  bool isPalindrome(ListNode* head) {
    ListNode *slow, *fast;
    slow = fast = head;
    while (fast != nullptr && fast->next != nullptr) {
      slow = slow->next;
      fast = fast->next->next;
    }
    if (fast != nullptr) {
      slow = slow->next;
    }
    ListNode *left, *right;
    left = head;
    right = reverse(slow);
    while (right != nullptr) {
      if (right->val != left->val) return false;
      right = right->next;
      left = left->next;
    }
    return true;
  }
  ListNode* reverse(ListNode* head) {
    ListNode *pre, *cur, *next;
    pre = nullptr;
    cur = next = head;
    while (cur != nullptr) {
      next = cur->next;
      cur->next = pre;
      pre = cur;
      cur = next;
    }
    return pre;
  }
};