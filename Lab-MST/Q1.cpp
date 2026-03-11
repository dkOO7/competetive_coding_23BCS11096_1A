class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        int n = tasks.size();
        sort(tasks.begin(), tasks.end(), [](auto & a , auto & b){
            if(abs(a[0]- a[1]) ==  abs(b[0]-b[1]))return a[1]>b[1];
            return a[1]- a[0] < b[1]-b[0];
        });

        for(auto i : tasks)cout<<i[0]<<" "<<i[1]<<endl;
        int ans =0;
        int c=0,val=0;
        for(auto i : tasks){
            c = max(c + i[0], i[1]);
        }
        return c;
    }
};
