/*Problem:
* Evaluate the value of an arithmetic expression in Reverse Polish Notation.
* 
* Valid operators are +, -, *, /. Each operand may be an integer or another expression.
* 
* Some examples:
*   ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
*   ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
* 
* 
* class Solution {
* public:
*     int evalRPN(vector<string> &tokens) {
* 	        
*     }
* };
*/

#include<iostream>
#include<vector>
#include<string.h>
using namespace std;
class Solution{
public:
	int isOperater(string *s){
		return (*s == "+" | *s == "-" | *s == "*" | *s == "/");
	}
	int evalRPN(vector<string> &tokens){
		vector<int> stack(1000);
		int index = 0, operand_left = 0, operand_right = 0;
		for(index = 0; index < tokens.size(); index++){
			if(!isOperater(&tokens[index])){
				stack.push_back(atoi(tokens[index].c_str()));
			}else{
				if(tokens[index] == "+"){
					operand_left  = stack.back();
					stack.pop_back();
					operand_right = stack.back();
					stack.pop_back();
					stack.push_back(operand_right + operand_left);
				}else if(tokens[index] ==  "-"){
					operand_left  = stack.back();
					stack.pop_back();
					operand_right = stack.back();
					stack.pop_back();
					stack.push_back(operand_right - operand_left);
				}else if(tokens[index] ==  "*"){
					operand_left  = stack.back();
					stack.pop_back();
					operand_right = stack.back();
					stack.pop_back();
					stack.push_back(operand_right * operand_left);
				}else if(tokens[index] ==  "/"){
					operand_left  = stack.back();
					stack.pop_back();
					operand_right = stack.back();
					stack.pop_back();
					stack.push_back(operand_right / operand_left);
				}
			}
		}
		return stack.back();
	}
};

//unit testing
int main(){
	Solution s;
	const string str1[] = {"2", "1", "+", "3", "*"};
	vector<string> svec(str1, str1 + 5);
	cout<<s.evalRPN(svec)<<endl;
	const string str2[] = {"4", "13", "5", "/", "+"};
	svec.assign(str2, str2 + 5);
	cout<<s.evalRPN(svec)<<endl;
	return 0;
}
