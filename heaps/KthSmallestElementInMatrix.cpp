#include<iostream>
#include<queue>
#include<vector>

using namespace std;
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {

        priority_queue<int, vector<int>, greater<int>> minHeap;

        for(int i = 0;i<matrix.size();i++){
            for(int j = 0;j<matrix[i].size();j++){
                minHeap.push(matrix[i][j]);
            }
        }

        for(int i = 1;i<k;i++){
            minHeap.pop();
        }

        return minHeap.top();
        
    }
};