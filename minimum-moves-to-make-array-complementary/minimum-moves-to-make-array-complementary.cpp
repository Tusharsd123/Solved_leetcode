class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
      int n = nums.size();
		int statechangeArr[ 2*limit + 2 ];
		memset(statechangeArr,0,sizeof(statechangeArr));
		int ans = INT_MAX;
		for(int i = 0 ;i < n/2; i++){
			statechangeArr[0]+=2;
			int cur_sum = nums[i] + nums[n - i - 1];


			statechangeArr[ cur_sum ] -= 1;
			statechangeArr[ cur_sum + 1 ] += 1;
			statechangeArr[ max( nums[i] + limit, nums[n - i - 1] + limit ) + 1 ] += 1;
			statechangeArr[ min( nums[i] + 1, nums[n - i - 1] + 1 ) ] -= 1;
		}
		int cur_num = 0;
		for(int state: statechangeArr){
			cur_num += state;
			ans = min(ans,cur_num);
		}
		return ans;
	}
};

// min - 2
// max - limit + max(arr[i])
//  2*limit