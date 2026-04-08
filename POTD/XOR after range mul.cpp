#include<stdio.h>
#include<stdlib.h>
using namespace std;
class Solution {
public:
    int xorAfterQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int Queries_count = queries.size();
        for (int i = 0; i < Queries_count; i++) {
            int idx = queries[i][0];
            int ri = queries[i][1];
            int vi = queries[i][3] ;
            int ki = queries[i][2] ;
            while (idx <= ri) {
                arr[idx] = 1LL *arr[idx] * vi % (1000000007);
                idx += ki;
            }
        }

        int res = arr[0];
        for (int i = 1; i < arr.size(); i++) {
            res = res ^ arr[i];
        }
        return res;
    }
};