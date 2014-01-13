/* Problem
 Sort a linked list using insertion sort.
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
*/

#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution{
public:
	int GetLen(ListNode *head){
		int len = 0;
		ListNode *cur_node = head;
		while(cur_node != NULL){
			len++;
			if(cur_node->next != NULL){
				cur_node = cur_node->next;
			}else{
				break;
			}
		}
		return len;
	}

	int partition(ListNode *head, int end_index){
        int index = 0;
		ListNode *base_node = head;
		ListNode *search_node = NULL, *save_node = NULL;
        
		int save_index = 0;
        int tmp = 0;
		index      = 1;
		search_node = base_node->next;
        
		save_node  = base_node;
		save_index = 0;
        while(index <= end_index){
            if(base_node->val >= search_node->val){
                tmp = save_node->next->val;
                save_node->next->val = search_node->val;
                search_node->val = tmp;
                
                save_node = save_node->next;
                save_index++;
            }
            search_node = search_node->next;
            index++;
        }
        tmp = base_node->val;
        base_node->val = save_node->val;
        save_node->val = tmp;
		return save_index;
	}

	void quick_sort(ListNode *head, int end_index){
		int index = 0;
		int i = 0;
		ListNode *cur_node = NULL;

		if(0 < end_index){
			index = partition(head, end_index);
			quick_sort(head, index - 1);
			cur_node = head;
			for(i = 0; i <= index; i++){
				cur_node = cur_node->next;
			}
			quick_sort(cur_node, end_index-index-1);

		}
	}

	ListNode *sortList(ListNode *head){
		int len = GetLen(head);
		quick_sort(head, len-1);
		return head;
	}
};


int main(){
	Solution s;
	ListNode *head = new ListNode(4);
	ListNode *tmp_node = head;

	int val = 4;
	int index = 0;
	for(index = 0; index < 4; index++){
		tmp_node->next = new ListNode(val - index - 1);
		tmp_node = tmp_node->next; 
	}

	cout<<"Orilist is: ";
	tmp_node = head;
	while(tmp_node != NULL){
		cout<<tmp_node->val<<"\t";
		tmp_node = tmp_node->next;
	}
	cout<<endl;

	head = s.sortList(head);
	cout<<"sorted list is: ";
	tmp_node = head;
	while(tmp_node != NULL){
		cout<<tmp_node->val<<"\t";
		tmp_node = tmp_node->next;
	}
	cout<<endl;

	delete []head;

	int data[10] = {4,19,14,5,-3,1,8,5,11,15};
	index = 0;
	head = new ListNode(data[index]);
	tmp_node = head;
	for(index = 1; index < 10; index++){
		tmp_node->next = new ListNode(data[index]);
		tmp_node = tmp_node->next; 
	}
	
	cout<<"Orilist is: ";
	tmp_node = head;
	while(tmp_node != NULL){
		cout<<tmp_node->val<<"\t";
		tmp_node = tmp_node->next;
	}

	cout<<endl;
	head = s.sortList(head);
	cout<<"sorted list is: ";
	tmp_node = head;
	while(tmp_node != NULL){
		cout<<tmp_node->val<<"\t";
		tmp_node = tmp_node->next;
	}
	cout<<endl;

	return 0;
}


