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

    ListNode* divide_and_conquer(vector<ListNode*>& lists, int left, int right){
        // this method will divide the lists untill we have two
        // lists, and then will divide and conquer sort
        if(left > right) return nullptr;
        if((right - left + 1) == 1) return lists[right];
        
        int middle = left + (right - left) / 2;
        return mergeLinks(divide_and_conquer(lists, left, middle), divide_and_conquer(lists, middle + 1, right));

       
    }

    ListNode* mergeLinks(ListNode* a, ListNode* b){
        ListNode* ret;

        if(!a && !b) return nullptr;
        if(!a) return b;
        if(!b) return a;

        
        if(a->val > b->val) std::swap(a, b);
        ListNode* head = a;
        while(a){
            ListNode* temp;
            while(a && a->val <= b->val){
                temp = a;
                a = a->next;
            }
            temp->next = b;
            if(a)
            std::swap(a, b);
        }

    return head;
    }
    
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return divide_and_conquer(lists, 0, lists.size() - 1);
        
      
    }
};
