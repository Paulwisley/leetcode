#include<vector>
#include<iostream>
using namespace std;


/**
 4Sum
 T18 @medium
 Given an array nums of n integers and an integer target, are there elements a, b, c, and d in nums such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.
 */
vector<vector<int> > fourSum(vector<int>& nums, int target){
    vector<vector<int> >answer;
    if(nums.empty()) return answer;
    vector<int> cur;
    sumHelper(answer, cur, nums, 0, target);
    return answer;
}

void sumHelper(vector<vector<int> >&ans，vector<int> &cur, vector<int> nums,int index, int target){
    if(cur.size() == 4){
        if(target == accumulate(cur.begin(), cur.end(), 0)){
            ans.push_back(cur);
        }else{
            return;
        }
    }
    int len = nums.size();
    for(int i = index; i < len; i++){
        for (int j = i ; j < len; j++) {
            cur.push_back(nums[j]);
            sumHelper(ans, cur, nums, index+1, target);
            cur.pop();
        }
    }
}

void mprint(vector<vector<int> >nums){
    int col = nums[0].size();
    int row = nums.size();
    for (int i = 0; i < col; i++) {
        for (int j = 0; j < row; j++) {
            cout<<nums[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    int tmp[6] = {1,0,-1,0,-2,2};
    vector<int> num(tmp, tmp+6);
    vector<vector<int> > ans = fourSum(nums, 0);
    mprint(ans);
}
