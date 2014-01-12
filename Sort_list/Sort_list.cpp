/* Problem
Sort a linked list in O(n log n) time using constant space complexity.
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

	int partition(ListNode *&head, int begin_index, int end_index){
    /*
		int index = 0;
		ListNode *base_node = head;
		ListNode *search_node = NULL, *save_node = NULL;
		ListNode *pre_node = NULL, *pre_save_node = NULL;
		ListNode *tmp_node = NULL;
   
		int save_index = 0;

		while(index < begin_index){
			pre_node  = base_node;
			base_node = base_node->next;
			index++;
		}
		index      = begin_index;
		search_node = base_node;
        
		save_node  = base_node;
		save_index = begin_index;

		while(index < end_index){
			if(base_node->val >= search_node->next->val){
                tmp_node = save_node->next;
				save_node->next = search_node->next;
				search_node->next = tmp_node;

				tmp_node = save_node->next->next;
				save_node->next->next = search_node->next->next;
				search_node->next->next = tmp_node;
				
				pre_save_node = save_node;
				save_node = save_node->next;
				save_index++;
			}
            search_node = search_node->next;
			index++;
		}
		
		if(begin_index == 0){
            if(pre_save_node != NULL){
                pre_save_node->next = base_node;
                tmp_node = base_node->next;
                base_node->next = save_node->next;
                save_node->next = tmp_node;
                head = save_node;
            }
		}else{
            if(pre_save_node != NULL){
                pre_save_node->next = base_node;
                pre_node->next = save_node;

                tmp_node = save_node->next;
                save_node->next = base_node->next;;
                base_node->next = tmp_node;
            }
		}
     */
        int index = 0;
		ListNode *base_node = head;
		ListNode *search_node = NULL, *save_node = NULL;
        
		int save_index = 0;
        int tmp = 0;
		while(index < begin_index){
			base_node = base_node->next;
			index++;
		}
		index      = begin_index+1;
		search_node = base_node->next;
        
		save_node  = base_node;
		save_index = begin_index;
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

	void quick_sort(ListNode *&head, int begin_index, int end_index){
		int index = 0;

		if(begin_index < end_index){
			index = partition(head, begin_index, end_index);
			quick_sort(head, begin_index, index - 1);
			quick_sort(head, index+1, end_index);
		}
	}

	ListNode *sortList(ListNode *head){
		int len = GetLen(head);
		quick_sort(head, 0, len-1);
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


