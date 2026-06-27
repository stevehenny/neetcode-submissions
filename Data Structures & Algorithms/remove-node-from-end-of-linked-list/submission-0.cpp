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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode* ptr = head;
        int count{};

        // Get count;
        while(ptr){
            ++count;
            ptr = ptr->next;
        }
        // reset pointer and calculate nth node loc
        ListNode* prev = nullptr;
        ptr = head;
        count -= n;

        while(count){
            --count;
            prev = ptr;
            ptr = ptr->next;
        }

        if(!prev){
            ptr = ptr->next;
            return ptr;
        }
        ptr = ptr->next;
        prev->next = ptr;
        
        return head;
    }
};
