#include<vector>
#include<iostream>

using namespace std;

//暴力拆解的最优解：——————————————————————————————————————
int searchInsert(vector<int>& nums, int target) {
	for (int i = 0; i < nums.size(); i++) {
		// 分别处理如下三种情况
		// 目标值在数组所有元素之前
		// 目标值等于数组中某一个元素  
		// 目标值插入数组中的位置 
		if (nums[i] >= target) { // 一旦发现大于或者等于target的num[i]，那么i就是我们要的结果
			return i;
		}
	}
	// 目标值在数组所有元素之后的情况 
	return nums.size(); // 如果target是最大的，或者 nums为空，则返回nums的长度
}


//------我写----------------
int searchInsert(vector<int>& nums, int target) {
	int i = 0;
	for (; i<nums.size(); i++)
	{
		if (nums[i] >= target)
			return i;
	}
	return i;

}




//二分法查找-----------------------------------------------------
int searchInsert(vector<int>& nums, int target) {
	int n = nums.size();
	int left = 0;
	int right = n - 1; // 定义target在左闭右闭的区间里，[left, right] 
	while (left <= right) { // 当left==right，区间[left, right]依然有效
		int middle = left + ((right - left) / 2);// 防止溢出 等同于(left + right)/2
		if (nums[middle] > target) {
			right = middle - 1; // target 在左区间，所以[left, middle - 1]
		}
		else if (nums[middle] < target) {
			left = middle + 1; // target 在右区间，所以[middle + 1, right]
		}
		else { // nums[middle] == target
			return middle;
		}
	}
	// 分别处理如下四种情况
	// 目标值在数组所有元素之前  [0, -1]
	// 目标值等于数组中某一个元素  return middle;
	// 目标值插入数组中的位置 [left, right]，return  right + 1
	// 目标值在数组所有元素之后的情况 [left, right]， return right + 1
	return right + 1;
}


//二分法.2
int searchInsert(vector<int>& nums, int target) {

	int n = nums.size();
	int left = 0, right = n - 1, ans = n;
	while (left <= right)
	{
		int mid = ((right - left) >> 1) + left;
		if (target <= nums[mid])
		{
			ans = mid;
			right = mid - 1;
		}
		else
			left = mid + 1;
	}
	return ans;
}