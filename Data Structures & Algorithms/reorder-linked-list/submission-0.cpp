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
    void reorderList(ListNode* head) {
        
        // first find the middle of the list
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast){
            fast = fast->next;
            if(!fast){
                break;
            }
            fast = fast->next;
            slow = slow->next;
        }
        
        ListNode* second = slow->next;
        ListNode* prev = slow->next = nullptr;
        while(second){
            ListNode* temp = second->next;
            second->next = prev;
            prev = second;
            second = temp;
            
        }
        // use headDup and slow as starting points for merge
        second = prev;
        ListNode* headDup = head;
        while(second){
            ListNode* temp1 = headDup->next;
            ListNode* temp2 = second->next;
            headDup->next = second;
            second->next = temp1;
            headDup  =temp1;
            second = temp2;
        }

    
        
    }
};
