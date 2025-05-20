#include<iostream>
#include<vector>
using namespace std;
 struct ListNode {
      int val;
      ListNode *next;
     ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        vector<ListNode*>adress;
        ListNode* p = head;
        while (p != nullptr) {
            adress.push_back(p);
            p = p->next;
        }
        //  
        int node_num = adress.size();
        for (int i = 0; i < adress.size(); i+=2) {
                swap(adress[i], adress[i + 1]);
        }
         for(int i=0;i<adress.size()-1;i++){
             adress[i]->next=adress[i+1];
         }
         adress.back()->next=nullptr;
        return head;
    }
};
int main() {
    ListNode* head=new ListNode(1);
    head->next=new ListNode(2);
    head->next->next=new ListNode(3);
    head->next->next->next=new ListNode(4);
    Solution s;
    s.swapPairs(head);
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
	return 0;
}