/*Problem
* 
* Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.i
* 
* Definition for a point.
* struct Point {
*     int x;
*     int y;
*     Point() : x(0), y(0) {}
*     Point(int a, int b) : x(a), y(b) {}
* };
* class Solution {
* public:
* 	int maxPoints(vector<Point> &points) {
* 	}
* };
*/
//题目意思，找住在一条直线上的最大点数

#include<iostream>
#include<vector>
using namespace std;

struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};
/* //方法一(Time Limit Exceeded)： 每来一点，先遍历之前所有的直线判断在哪些直线，然后再遍历之前的点构造直线，遍历整个空间后得到所有的直线以及该直线上的点数，再寻找最大的直线
class Solution1 {
private:
//	vector<int> point_number_on_the_line;
//	vector<Point> line; //每条线只存2个点，新点若再线上则只计数，不存储，否则则建立新线(多条)
//  遍历搜索
	bool equal_almost(double x, double y){
		return (x - y < 0.000001 && x - y > -0.000001);
	}
public:
	int maxPoints(vector<Point> &points) {
		vector<double> k;
		vector<double> b;
		vector<int>    num;

		int point_num = points.size(), point_index = 0, pre_point_index = 0; 
		int line_num  = 0, line_index = 0, cur_line_num = 0, pre_line_index = 0;	
		int cur_x = 0, cur_y = 0;
		int cur_k = 0, cur_b = 0;
		double y_line = 0.0;
		bool has_same_line = false;
		int max_point_num = 0;
		if(point_num < 2){
			max_point_num = 0;
		}else if(point_num == 2){
			max_point_num = 2;
		}else{
			//不考虑多点重合
			line_num++;
			k.push_back((points[0].y - points[1].y) / (1.0 * (points[0].x - points[1].x)));
			b.push_back(points[0].y - k.back()* points[0].x);
			num.push_back(2);
			for(point_index = 2; point_index < point_num; point_index++){
				cur_line_num = line_num;
				cur_x = points[point_index].x;
				cur_y = points[point_index].y;
				for(line_index = 0; line_index < cur_line_num; line_index++){
					y_line = cur_x * k[line_index] + b[line_index];
					if(equal_almost(y_line, cur_y)){
						num[line_index]++;
					}
				}
				for(pre_point_index = 0; pre_point_index < point_index; pre_point_index++){
					cur_k = (cur_y - points[pre_point_index].y) / (1.0 * (cur_x - points[pre_point_index].x));
					cur_b = cur_y - cur_k * cur_x;
					has_same_line = false;
					for(pre_line_index = 0; pre_line_index < cur_line_num; pre_line_index++){
						if(equal_almost(cur_k, k[pre_line_index]) && equal_almost(cur_b, b[pre_line_index])){
							has_same_line = true;
							break;
						}
					}
					if(!has_same_line){
						k.push_back(cur_k);
						b.push_back(cur_b);
						num.push_back(2);
						line_num++;
					}
				}
			}
			
			for(line_index = 0; line_index < line_num; line_index++){
				if(max_point_num < num[line_index]){
					max_point_num = num[line_index];
				}
			}
		}

		return max_point_num;
	}
};
//*/
/*
* 方法2： 计算过每点的每条线上的点数
*/
class Solution {
public:
	int maxPoints(vector<Point> &points) {
		int globe_max_point = 0, line_max_point = 0, line_point = 0;
		int point_index = 0, point_num = points.size(), cur_point_index = 0, test_point_index = 0;    
		int same_point_num = 0;

		if(point_num < 1){
			globe_max_point = 0;
		}else if(point_num < 2){
			globe_max_point = 1;
		}else if(point_num == 2){
			globe_max_point = 2;
		}else{
			for(point_index	= 0; point_index < point_num; point_index++){
				line_max_point = 0;
				same_point_num = 0;
				for(cur_point_index = 0; cur_point_index < point_num; cur_point_index++){
					if(points[point_index].y == points[cur_point_index].y && points[point_index].x == points[cur_point_index].x){
						same_point_num++;
					}
				}
					
				for(cur_point_index = point_index + 1; cur_point_index < point_num; cur_point_index++){
					if(points[point_index].y == points[cur_point_index].y && points[point_index].x == points[cur_point_index].x){
						line_point = same_point_num;
						continue;
					}else{
						line_point = same_point_num+1;
					}

					for(test_point_index = cur_point_index + 1; test_point_index < point_num; test_point_index++){
						if(points[cur_point_index].y == points[test_point_index].y && points[cur_point_index].x == points[test_point_index].x){
							line_point++;
						}else if(points[point_index].y == points[cur_point_index].y){
							if(points[point_index].y == points[test_point_index].y) {
								line_point++;
							}
						}else if(points[point_index].x == points[test_point_index].x){
							if(points[point_index].x == points[cur_point_index].x) {
								line_point++;
							}
						}else{
							if((points[point_index].y - points[cur_point_index].y)*(points[point_index].x - points[test_point_index].x) == (points[point_index].y - points[test_point_index].y)*(points[point_index].x - points[cur_point_index].x)){
								line_point++;
							}
						}
					}

					if(line_max_point < line_point){
						line_max_point = line_point;
					}
				}
				if(globe_max_point < same_point_num){
					globe_max_point = same_point_num;
				}
				if(globe_max_point < line_max_point){
					globe_max_point = line_max_point;
				}
			}
		}

	return globe_max_point;	
	}
};

int main(){
	Solution s;
	vector<Point> v_p;
	Point t_p(1, 1);
	v_p.push_back(t_p);	
	t_p.x = 2;
	t_p.y = 2;
	v_p.push_back(t_p);	
	t_p.x = 3;
	t_p.y = 3;
	v_p.push_back(t_p);	
	cout<<"right answer is: 3"<<endl;
	cout<<"real  answer is: "<<s.maxPoints(v_p)<<endl;
	v_p[2].x = 3;
	v_p[2].y = 4;	
	cout<<"right answer is: 2"<<endl;
	cout<<"real  answer is: "<<s.maxPoints(v_p)<<endl;

	//test wrong example;
	v_p.clear();
	cout<<"right answer is: 0"<<endl;
	cout<<"real  answer is: "<<s.maxPoints(v_p)<<endl;

	t_p.x = 0;
	t_p.y = 0;
	v_p.push_back(t_p);	
	t_p.x = -1;
	t_p.y = -1;
	v_p.push_back(t_p);	
	t_p.x = 2;
	t_p.y = 2;
	v_p.push_back(t_p);	
	cout<<"right answer is: 3"<<endl;
	cout<<"real  answer is: "<<s.maxPoints(v_p)<<endl;

	v_p.clear();
	t_p.x = 0;
	t_p.y = 9;
	v_p.push_back(t_p);	
	t_p.x = 138;
	t_p.y = 429;
	v_p.push_back(t_p);	
	t_p.x = 115;
	t_p.y = 359;
	v_p.push_back(t_p);	
	t_p.x = 115;
	t_p.y = 359;
	v_p.push_back(t_p);	
	cout<<"right answer is: 4"<<endl;
	cout<<"real  answer is: "<<s.maxPoints(v_p)<<endl;
	v_p.clear();
	t_p.x =0;t_p.y = 9;v_p.push_back(t_p);t_p.x =138;t_p.y = 429;v_p.push_back(t_p);t_p.x =115;t_p.y = 359;v_p.push_back(t_p);t_p.x =115;t_p.y = 359;v_p.push_back(t_p);t_p.x =-30;t_p.y = -102;v_p.push_back(t_p);t_p.x =230;t_p.y = 709;v_p.push_back(t_p);t_p.x =-150;t_p.y = -686;v_p.push_back(t_p);t_p.x =-135;t_p.y = -613;v_p.push_back(t_p);t_p.x =-60;t_p.y = -248;v_p.push_back(t_p);t_p.x =-161;t_p.y = -481;v_p.push_back(t_p);t_p.x =207;t_p.y = 639;v_p.push_back(t_p);t_p.x =23;t_p.y = 79;v_p.push_back(t_p);t_p.x =-230;t_p.y = -691;v_p.push_back(t_p);t_p.x =-115;t_p.y = -341;v_p.push_back(t_p);t_p.x =92;t_p.y = 289;v_p.push_back(t_p);t_p.x =60;t_p.y = 336;v_p.push_back(t_p);t_p.x =-105;t_p.y = -467;v_p.push_back(t_p);t_p.x =135;t_p.y = 701;v_p.push_back(t_p);t_p.x =-90;t_p.y = -394;v_p.push_back(t_p);t_p.x =-184;t_p.y = -551;v_p.push_back(t_p);t_p.x =150;t_p.y = 774;v_p.push_back(t_p);
	s.maxPoints(v_p);
	cout<<"right answer is: 12"<<endl;
	cout<<"real  answer is: "<<s.maxPoints(v_p)<<endl;

	v_p.clear();
	t_p.x = 1;
	t_p.y = 1;
	v_p.push_back(t_p);	
	t_p.x = 1;
	t_p.y = 1;
	v_p.push_back(t_p);	
	t_p.x = 1;
	t_p.y = 1;
	v_p.push_back(t_p);	
	cout<<"right answer is: 3"<<endl;
	cout<<"real  answer is: "<<s.maxPoints(v_p)<<endl;


	v_p.clear();
	t_p.x = 1;
	t_p.y = 1;
	v_p.push_back(t_p);	
	t_p.x = 1;
	t_p.y = 1;
	v_p.push_back(t_p);	
	t_p.x = 2;
	t_p.y = 3;
	v_p.push_back(t_p);	
	cout<<"right answer is: 3"<<endl;
	cout<<"real  answer is: "<<s.maxPoints(v_p)<<endl;

	v_p.clear();
	t_p.x = 1;
	t_p.y = 1;
	v_p.push_back(t_p);	
	t_p.x = 1;
	t_p.y = 1;
	v_p.push_back(t_p);	
	t_p.x = 2;
	t_p.y = 2;
	v_p.push_back(t_p);	
	t_p.x = 2;
	t_p.y = 2;
	v_p.push_back(t_p);	
	cout<<"right answer is: 4"<<endl;
	cout<<"real  answer is: "<<s.maxPoints(v_p)<<endl;

	v_p.clear();
	t_p.x = 0;
	t_p.y = 0;
	v_p.push_back(t_p);	
	t_p.x = 1;
	t_p.y = 1;
	v_p.push_back(t_p);	
	t_p.x = 0;
	t_p.y = 0;
	v_p.push_back(t_p);	
	cout<<"right answer is: 3"<<endl;
	cout<<"real  answer is: "<<s.maxPoints(v_p)<<endl;
	return 0;
}
