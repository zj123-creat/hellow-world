#include<vector>
#include<iostream>

using namespace std;


vector<int> plusOne(vector<int>& digits) {
	for (int i = digits.size() - 1; i >= 0; i--)
	{
		digits[i]++;
		if (digits[i] == 10)  digits[i] = 0;
		else  return digits;
	}
	digits.insert(digits.begin(), 1);
	return digits;
}


//½â·¨¶þ
vector<int> plusOne(vector<int>& digits) {
	int i = digits.size() - 1;
	bool plus = true;
	for (; i >= 0; i--)
	{
		if (plus)
		{
			if (digits[i] == 9)
			{
				plus = true;
				digits[i] = 0;
			}
			else
			{
				digits[i] += 1;
				plus = false;
			}
		}
		else
			break;
	}
	if (digits[0] == 0 && plus)
	{
		digits[0] = 1;
		digits.push_back(0);
	}
	return digits;
}