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
    void Swap(ListNode* &head){
        ListNode* temp = head;
        if(temp == NULL || temp->next == NULL) return;
        if(temp->next->next == NULL){
            int tempo1 = temp->val;
            int tempo2 = temp->next->val;
            temp->next->val = tempo1;
            temp->val = tempo2;
            return;
        }
        int v1 = temp->val;
        int v2 = temp->next->val;
        temp->next->val = v1;
        temp->val = v2;
        Swap(temp->next->next);
    }
    ListNode* swapPairs(ListNode* head) {
        Swap(head);
        return head;
    }
};