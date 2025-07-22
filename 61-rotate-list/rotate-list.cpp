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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head)return nullptr;
        if(k==0)return head;
        struct ListNode *last=head;
        struct ListNode *curr=head;
        int count=1;
        while(last->next!=nullptr){
            count++;
            last=last->next;
        }
       struct ListNode *inner=nullptr;
         struct ListNode *inner1=nullptr;
        if(k<count){
             int needed=count-k;
            for(int i=0;i<needed-1;i++){
                curr=curr->next;
            }
            inner=curr->next;
            curr->next=nullptr;
            last->next=head;
            return inner;

        }
        else if(k>count){
            int mod=k%count;
            if(mod==0)return head;
            int needed=count-mod;

            for(int i=0;i<needed-1;i++){
           curr=curr->next;
            }
            inner1=curr->next;
             curr->next=nullptr;
            last->next=head;
            return inner1;
            
        }
        else{
            return head;

        }
        
        return curr;
    }
};