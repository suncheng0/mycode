#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int>path;
    vector<vector<int>>ans;
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<bool>used(nums.size(), false);
        backtracking(0, nums, used);
        return ans;
    }
    void backtracking(int index, vector<int>& nums, vector<bool>& used) {
        if (index > nums.size())return;
        if (index == nums.size()) {
            return;
        }
        for (int i = index; i < nums.size(); i++) {
            if (path.size() > 0 && nums[i] < path.back())continue;
            if (i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false)continue;
            path.push_back(nums[i]);
            if (path.size() > 1)ans.push_back(path);
            used[i] = true;
            backtracking(i + 1, nums, used);
            used[i] = false;
            path.pop_back();
        }
    }
};
int main() {
    vector<int>input = { 1,2,3,1,2,3 };
    Solution a;
    vector<vector<int>>output = a.findSubsequences(input);
    for (auto k : output) {
        for (auto l : k)cout << l << " ";
        cout << endl;
    }
    return 0;
;}