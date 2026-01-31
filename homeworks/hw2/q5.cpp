class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<long long, int> mp;
        mp[0] = 1;

        long long s = 0;
        int res = 0;

        for (const int num : nums) {
            s += num;

            auto it = mp.find(s - k);
            if (it != mp.end()) res += it->second;

            mp[s] += 1;
        }
        return res;
    }
};
