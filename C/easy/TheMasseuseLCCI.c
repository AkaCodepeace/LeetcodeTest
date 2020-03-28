/*一个有名的按摩师会收到源源不断的预约请求，每个预约都可以选择接或不接。
在每次预约服务之间要有休息时间，因此她不能接受相邻的预约。
给定一个预约请求序列，替按摩师找到最优的预约集合（总预约时间最长），返回总的分钟数。

注意：本题相对原题稍作改动

示例 1：

输入： [1,2,3,1]
输出： 4
解释： 选择 1 号预约和 3 号预约，总时长 = 1 + 3 = 4。
示例 2：

输入： [2,7,9,3,1]
输出： 12
解释： 选择 1 号预约、 3 号预约和 5 号预约，总时长 = 2 + 9 + 1 = 12。
*/

//解题思路：运用一个数组，来存储所累加总时长最长的时间 。
#include<stdio.h>

#define Max(a, b)  a>b? a:b

int massage(int* nums, int numsSize);

int main(){
	
	int nums[5] = {2,7,9,3,1};
	printf("%d", massage(nums, 5));
	return 0;
}

//主要方法 
int massage(int* nums, int numsSize){
	int i;
	
    if(numsSize == 0){
    	return 0;
	} 
	
	int dp[numsSize];
	
	for(i=0; i<numsSize; i++){
		if(i == 0){
			dp[i] = nums[i];
		} else if(i == 1){
			dp[i] = Max(nums[0], nums[1]);
		} else {
			dp[i] = Max(dp[i-1], dp[i-2]+nums[i]);
		} 
	} 
	
	return dp[numsSize-1];
}
