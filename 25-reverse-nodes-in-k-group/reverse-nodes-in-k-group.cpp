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
    ListNode* reverseKGroup(ListNode* head, int k) {
        vector<int>vc;
        struct ListNode *dummy=head;
        int n=0;
        while(dummy!=nullptr){
            n++;
            vc.push_back(dummy->val);
            dummy=dummy->next;
        }
        for(int i=0;i+k<=n;i+=k){
            reverse(vc.begin()+i,vc.begin()+i+k);
        }
        int i=0;
          struct ListNode *dummy1=head;
          while(dummy1!=nullptr){
            dummy1->val=vc[i++];
            dummy1=dummy1->next;
          }
return head;
    }
};