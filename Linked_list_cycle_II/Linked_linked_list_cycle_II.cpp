/* Problem
* Given a linked list, return the node where the cycle begins. If there is no cycle, return null.
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
* 	ListNode *detectCycle(ListNode *head) {
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
    ListNode *detectCycle(ListNode *head) {
		ListNode *fast_node_searcher = NULL, *slow_node_searcher = NULL;           
		ListNode *node_searcher = NULL;
		ListNode *tmp;
		bool b_slow_node_move = true;
		if(head == NULL || head->next == NULL){
			return NULL;
		}else{
			slow_node_searcher = head;
			fast_node_searcher = head->next;
			//判断是否存在cycle
			while(slow_node_searcher != fast_node_searcher){
				if(fast_node_searcher->next == NULL){
					return NULL;
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

			//存在cycle, slow_node_searcher一定在cycle中
			//从head开始每个节点遍历，第一个在循环中的node为环的头
			tmp = head;
			while(tmp != node_searcher){
				node_searcher = slow_node_searcher->next;
				while(node_searcher != slow_node_searcher){
					if(tmp == node_searcher){
						return tmp;
					}else{
						node_searcher = node_searcher->next;
					}
				}
				tmp = tmp->next;
			}

			return tmp; //开始无该语句导致bug
		}
    }
};

int main(){
	ListNode *l = NULL, *tmp = NULL;
	Solution s;
	int i = 0;

	cout<<"test example 1: NULL list\n";
	cout<<s.detectCycle(l)<<endl;

	cout<<"test example 2: No cycle\n";
	l = new ListNode(0);
	tmp = l;
	for(i = 1; i < 4; i++){
		tmp->next = new ListNode(i);	
		tmp = tmp->next;
	}
	cout<<s.detectCycle(l)<<endl;


	cout<<"test example 3: has  cycle, the cycle head value is 1\n";
	tmp->next = l->next;
	cout<<s.detectCycle(l)->val<<endl;
	
	cout<<"test example 4: the Bug,{1}, tail connects to node index 0, the cycle head value is 0\n";
	l->next = l;
	cout<<s.detectCycle(l)->val<<endl;
	return 0;
}
