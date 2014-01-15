/* Problem
* Given a singly linked list L: L0→L1→…→Ln-1→Ln,
* reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…
* 
* You must do this in-place without altering the nodes' values.
* 
* For example,
* Given {1,2,3,4}, reorder it to {1,4,2,3}.
* 
* Definition for singly-linked list.
* struct ListNode {
*    int val;
*    ListNode *next;
*    ListNode(int x) : val(x), next(NULL) {}
* };
* class Solution {
* public:
*    void reorderList(ListNode *head) {
*          
*    }
* };
*/

#include<iostream>
#include<vector>
using namespace std;

struct ListNode {
	int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
	vector<ListNode*> list;
    void reorderList(ListNode *head) {
	 	ListNode *tmp = head;          
		int begin = 0, end = 0;
		while(tmp != NULL){
			list.push_back(tmp);
			tmp = tmp->next;
		}

		begin = 1;
		end   = list.size() - 1;
		tmp = head;
		while(begin < end){
			tmp->next = list[end];
			tmp = tmp->next;
			tmp->next = list[begin];
			tmp = tmp->next;
			begin++;
			end--;
		}

		if(begin == end){
			tmp->next = list[begin];
			tmp = tmp->next;
		}
		
		if(tmp != NULL){
			tmp->next = NULL;
		}

    }
};


int main(){
	Solution s;
	ListNode *link_list = new ListNode(1);
	ListNode *tmp = link_list;
	int value[4] = {1, 2, 3, 4};
	int i = 0;

	for(i = 1; i < 4; i++){
		tmp->next = new	ListNode(value[i]);
		tmp = tmp->next;
	}
	
	cout<<"ori_list is: ";
	tmp = link_list;
	while(tmp != NULL){
		cout<<tmp->val<<"\t";
		tmp = tmp->next;
	}

	s.reorderList(link_list);
	cout<<"reorder_list is: ";
	tmp = link_list;
	while(tmp != NULL){
		cout<<tmp->val<<"\t";
		tmp = tmp->next;
	}
	
	cout<<"test example 2:\n";
	Solution s1;
	ListNode *link_test = NULL;
	s1.reorderList(link_test);
	return 0;
}
