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


// iteratively get the smallest among the lists and add to new list. like a pointer based solution
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* res = new ListNode();
        ListNode* cur = res;

        auto comp = [](ListNode* a, ListNode* b){
            return a->val> b->val;
        };

        priority_queue<ListNode*, vector<ListNode*>, decltype(comp)> pq;
        for(int i =0 ; i<lists.size() ;i++){
            if(lists[i] == NULL) continue;
            pq.emplace(lists[i]);
        }

        while(!pq.empty()){
            ListNode* p = pq.top();
            pq.pop();

            cur->next = p;
            p = p->next;
            if(p!=NULL)
                pq.emplace(p);
            cur=cur->next;
        }
        return res->next;
    }
};
