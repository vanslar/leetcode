/* Problem
* Given a linked list, determine if it has a cycle in it.
* 
* Follow up:
* Can you solve it without using extra space?
* 
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
* class Solution {
* public:
* 	bool hasCycle(ListNode *head) {
* 	           
* 	}
* };
*/

#include<iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    bool hasCycle(ListNode *head) {
		ListNode *fast_node_searcher = NULL, *slow_node_searcher = NULL;           
		bool b_slow_node_move = true;
		if(head == NULL || head->next == NULL){
			return false;
		}else{
			slow_node_searcher = head;
			fast_node_searcher = head->next;
			//判断是否存在cycle
			while(slow_node_searcher != fast_node_searcher){
				if(fast_node_searcher->next == NULL){
					return false;
				}else{
					fast_node_searcher = fast_node_searcher->next;
					if(b_slow_node_move){
						slow_node_searcher = slow_node_searcher->next;
						b_slow_node_move = false;
					}else{
						b_slow_node_move = true;
					}
				}
			}
		}

		return true;
	}
};

int main(){
	ListNode *l = NULL, *tmp = NULL;
	Solution s;
	int i = 0;

	cout<<"test example 1: NULL list\n";
	cout<<s.hasCycle(l)<<endl;

	cout<<"test example 2: No cycle\n";
	l = new ListNode(0);
	tmp = l;
	for(i = 1; i < 4; i++){
		tmp->next = new ListNode(i);	
		tmp = tmp->next;
	}
	cout<<s.hasCycle(l)<<endl;

	cout<<"test example 3: has  cycle, the cycle head value is 1\n";
	tmp->next = l->next;
	cout<<s.hasCycle(l)<<endl;

	cout<<"test example 4: only one node\n";
	l->next = l;
	cout<<s.hasCycle(l)<<endl;
	return 0;
}
