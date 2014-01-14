/*Problem
* Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and set.
* 
* get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
* set(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.
* 
* class LRUCache{
* public:
*     LRUCache(int capacity) {
* 	        
*     }
* 			    
*     int get(int key) {
* 						        
*     }
* 									    
*     void set(int key, int value) {
* 											        
*     }
* };
*/

#include<iostream>
#include<vector>
using namespace std;
//初次设计所用的数据结构是数组，方案错误，因为数组在重排按访问顺序时比链表效率低很多

class LRUCache{
public:
    typedef struct ListNode{
    	int key;
    	int value;
    	ListNode *next;
    	ListNode(): key(-1), value(-1), next(NULL){};
    } LN;

	LN *LRU_head;
	int LRU_capacity;

    LRUCache(int capacity) {
		LN *tmp = NULL; //LRU_head未new之前为NULL，new之后指针地址改变，因此此时赋值为LRU_head无效
		int i = 0;
		LRU_head = new LN[capacity];
		tmp = LRU_head; //LRU_head未new之前为NULL，new之后指针地址改变，因此此时赋值为LRU_head无效
		LRU_capacity = capacity;
		for(i = 0; i < capacity - 1; i++){
			tmp->key = -1;
			tmp->value = -1;
			tmp->next = LRU_head + i + 1;
			tmp = tmp->next;
		}

		tmp->key = -1;
		tmp->value = -1;
		tmp->next = NULL;
    }
				    
    int get(int key) {
	//访问时需要将节点放最早
		LN *tmp = LRU_head, *tmp1 = NULL;;	
		LN *pre_node = LRU_head;
		int key_val = -1;
		while(tmp != NULL){
			if(tmp->key == key){
				key_val = tmp->value;
				//指针交换顺序很重要，当不同指针指向同一地址时不能出现死循环
				tmp1 = tmp->next;
				tmp->next = LRU_head;
				pre_node->next = tmp1;
				LRU_head = tmp;
				break;
			}
			pre_node = tmp;
			tmp = tmp->next;
		}
		
		return key_val;
	}					        
									    
    void set(int key, int value) {
		LN *tmp = LRU_head, *search_node = LRU_head;
	//	LN *pre_node = NULL;
		LN *pre_node = LRU_head; //初始为NULL会导致调用前为赋值
		

		search_node = LRU_head;
		pre_node    = LRU_head;
		while(search_node->next != NULL){  
			if(search_node->key == key){
				tmp = search_node->next;
				search_node->next = LRU_head;
				search_node->value = value;
				pre_node->next = tmp;
				LRU_head = search_node;
				return;
			}	
			pre_node = search_node;
			search_node = search_node->next;
		}
		//不论最后一个节点的key是否匹配，处理方法一样
		search_node->key = key;
		search_node->value = value;
		search_node->next = LRU_head;
		pre_node->next = NULL;
		LRU_head = search_node;
		return;
    }
};


int main(){
/*
	LRUCache c(5);

	cout<<c.get(5)<<endl;;
	c.set(5, 4);
	cout<<c.get(5)<<endl;;
*/
	cout<<"test example 1:\n";	
	LRUCache c(1);
	c.set(2, 1);
	cout<<c.get(1)<<endl;;
	cout<<c.get(2)<<endl;;

	cout<<"test example 2:\n";	
	LRUCache c1(2);
	c1.set(2,1);
	c1.set(2,2);
	cout<<c1.get(2)<<endl;
	c1.set(1,1);
	c1.set(4,1);
	cout<<c1.get(2)<<endl;
	cout<<"the right answer is : 2 -1\n";


	cout<<"test example 3:\n";	
	LRUCache c2(2);
	c2.set(2,1);
	c2.set(1,1);
	cout<<c2.get(2)<<endl;
	c2.set(4,1);
	cout<<c2.get(1)<<endl;
	cout<<c2.get(2)<<endl;


	return 0;
}
