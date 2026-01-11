class Solution {
public:
    vector<int> nextSmaller(vector<int>arr, int n){
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);
        for(int i=n-1; i>=0; i--){
            while(s.top() != -1 && arr[s.top()] >= arr[i]){
                s.pop();
            }
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }
    vector<int> prevSmaller(vector<int>arr, int n){
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);
        for(int i=0; i<n; i++){
            while(s.top() != -1 && arr[s.top()] >= arr[i]){
                s.pop();
            }
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }
    int largestRowArea(vector<int>& arr){
        int n = arr.size();
        vector<int> next;
        next = nextSmaller(arr, n);

        vector<int> prev;
        prev = prevSmaller(arr, n);

        int maxArea = 0;
        for(int i=0; i<n; i++){
            if(next[i] == -1){
                next[i] = n;
            }
            int length = arr[i];
            int breadth = next[i] - prev[i] - 1;
            int area = length * breadth;
            maxArea = max(maxArea, area);            
        }
        return maxArea;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        vector<vector<int>> v;
        for(int i=0; i<rows; i++){
            vector<int> temp;
            for(int j=0; j<cols; j++){
                temp.push_back(matrix[i][j] - '0');
            }
            v.push_back(temp);
        }

        int area = largestRowArea(v[0]);
        for(int i=1; i<rows; i++){
            for(int j=0; j<cols; j++){
                if(v[i][j] != 0){
                    v[i][j] = v[i][j] + v[i-1][j];
                }
                else{
                    v[i][j] = 0;
                }
            }
            area = max(area, largestRowArea(v[i]));
        }   
        return area;
    }
};