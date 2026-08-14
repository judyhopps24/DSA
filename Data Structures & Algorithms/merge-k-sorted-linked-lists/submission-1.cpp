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

struct Node{
    int value;
    ListNode* llnode;
    int index;

    bool operator<(const Node& other) const {
        return value > other.value; 
    }
};
public:


// iteratively get the smallest among the lists and add to new list. like a pointer based solution
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* res = new ListNode();
        ListNode* cur = res;

        priority_queue<Node> pq;
        for(int i =0 ; i<lists.size() ;i++){
            if(lists[i] == NULL) continue;
            pq.emplace(lists[i]->val, lists[i], i);
        }

        while(!pq.empty()){
            Node p = pq.top();
            pq.pop();

            cur->next = p.llnode;
            lists[p.index] = lists[p.index]->next;
            if(lists[p.index]!=NULL)
                pq.emplace(lists[p.index]->val, lists[p.index], p.index);
            cur=cur->next;
        }
        return res->next;
    }
};
