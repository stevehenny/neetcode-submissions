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
private:
    ListNode* reverseNode(ListNode* head){
        ListNode* prev = nullptr;

        while(head){
            ListNode* temp = head->next;
            head->next = prev;
            prev = head;
            head = temp;
        }
        return prev;
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        // first reverse both lists
        // l1 = reverseNode(l1);
        // l2 = reverseNode(l2);
   
        // now iterate through reverse lists and add
        int overflow{};
        ListNode* ret = new ListNode();
        ListNode* ptr = ret;
        while(l1 || l2){
            if(l1 && l2){
                int val = (l1->val + l2->val + overflow);
                int mod = val % 10;
                overflow = val / 10;
                ptr->next = new ListNode(mod);
                ptr = ptr->next;
                l1 = l1->next;
                l2 = l2->next;
            }
            else if(l1){
                int val = (l1->val + overflow);
                int mod = val % 10;
                overflow = val / 10;
                ptr->next = new ListNode(mod);
                ptr = ptr->next;
                l1 = l1->next;
            }
            else{
                int val = (l2->val + overflow);
                int mod = val % 10;
                overflow = val / 10;
                ptr->next = new ListNode(mod);
                ptr = ptr->next;
                l2 = l2->next;
            }
        }

        if(overflow){
            ptr->next = new ListNode(overflow);
        }
        return ret->next;
    }
};
