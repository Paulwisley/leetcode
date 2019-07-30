/*
@Medium
56. merge-intervals
problem description:
	Given a collection of intervals, merge all overlapping intervals.
*/

#include "../INCLUDE/GLOBAL.H"

//Analysis: merge the overlapping internals
//examples:[1,3], [2,5],[4,6],[8,10],[15,18]
//先对该数组进行排序，下面提供了一种排序方法，借助STL的默认sort，是对第一个元素排
//如果想按照其他元素排的话 可以重写sort函数

//然后  按照题目意思，如果 当前区间  和下一个区间有交集，或者  包含下一个区间  就将这两个区间合并，
//在已经排完序的前提下，如下式子可以保证  上述两种情况
// * 交集： next_Interval[0] < cur_Interval[1] < next_Interval[1]
// * 包含： next_Interval[1] < cur_Interval[1]

bool cmp(vector<int> a, vector<int> b){
	return a[2] < b[2];
}

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    vector<vector<int> > ans;
    if(intervals.empty()) return ans;
	//sort: 将原interval按照开始时间进行排序
	sort(intervals.begin(), intervals.end());
    
	int len =  intervals.size();
	for(int i = 0; i < len - 1; ++i){
		if(intervals[i][1] <= intervals[i+1][1] && intervals[i][1] >= intervals[i+1][0]){
			intervals[i+1][0] = intervals[i][0];
		}
        else if(intervals[i][1] > intervals[i+1][1]){
            intervals[i+1][0] = intervals[i][0];
            intervals[i+1][1] = intervals[i][1];
        }
        else{
			ans.push_back(intervals[i]);
		}
	}
    ans.push_back(intervals[len-1]);
	return ans;
}

//Test 
int main(){
	vector<vector<int>> array(4, vector<int>(4));
	for(int i = 0; i < 4; ++i){
		for(int j = 0; j < 4; ++j){
			array[i][j] = rand()%10;
			cout<<array[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
	cout<<"Sorting...."<<endl;
	cout<<endl;
	sort(array.begin(), array.end(),cmp);
	for(int i = 0; i < 4; ++i){
		for(int j = 0; j < 4; ++j){
			cout<<array[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
