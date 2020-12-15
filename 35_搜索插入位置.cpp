#include<vector>
#include<iostream>

using namespace std;

//�����������Ž⣺����������������������������������������������������������������������������
int searchInsert(vector<int>& nums, int target) {
	for (int i = 0; i < nums.size(); i++) {
		// �ֱ��������������
		// Ŀ��ֵ����������Ԫ��֮ǰ
		// Ŀ��ֵ����������ĳһ��Ԫ��  
		// Ŀ��ֵ���������е�λ�� 
		if (nums[i] >= target) { // һ�����ִ��ڻ��ߵ���target��num[i]����ôi��������Ҫ�Ľ��
			return i;
		}
	}
	// Ŀ��ֵ����������Ԫ��֮������ 
	return nums.size(); // ���target�����ģ����� numsΪ�գ��򷵻�nums�ĳ���
}


//------��д----------------
int searchInsert(vector<int>& nums, int target) {
	int i = 0;
	for (; i<nums.size(); i++)
	{
		if (nums[i] >= target)
			return i;
	}
	return i;

}




//���ַ�����-----------------------------------------------------
int searchInsert(vector<int>& nums, int target) {
	int n = nums.size();
	int left = 0;
	int right = n - 1; // ����target������ұյ������[left, right] 
	while (left <= right) { // ��left==right������[left, right]��Ȼ��Ч
		int middle = left + ((right - left) / 2);// ��ֹ��� ��ͬ��(left + right)/2
		if (nums[middle] > target) {
			right = middle - 1; // target �������䣬����[left, middle - 1]
		}
		else if (nums[middle] < target) {
			left = middle + 1; // target �������䣬����[middle + 1, right]
		}
		else { // nums[middle] == target
			return middle;
		}
	}
	// �ֱ��������������
	// Ŀ��ֵ����������Ԫ��֮ǰ  [0, -1]
	// Ŀ��ֵ����������ĳһ��Ԫ��  return middle;
	// Ŀ��ֵ���������е�λ�� [left, right]��return  right + 1
	// Ŀ��ֵ����������Ԫ��֮������ [left, right]�� return right + 1
	return right + 1;
}


//���ַ�.2
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