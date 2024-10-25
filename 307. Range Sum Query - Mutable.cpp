class NumArray {
    vector<int> seg;
    int n;
private:
    void build(int ind, int low, int high, vector<int>& nums){
        if(low==high){
            seg[ind] = nums[low];
            return;
        }
        int mid = (low+high)/2;
        build(2*ind+1,low,mid,nums);
        build(2*ind+2,mid+1,high,nums);

        seg[ind] = seg[2*ind+1] + seg[2*ind+2];
    }
    int query(int ind, int low, int high, int l, int r){
        if(r<low || high<l){ // non-overlapping
            return 0;
        }
        if(l<=low && high<=r){ // complete overlapping
            return seg[ind];
        }
        // partial overlapping
        int mid = (low+high)/2;
        int left = query(2*ind+1,low,mid,l,r);
        int right = query(2*ind+2,mid+1,high,l,r);

        return left+right;
    }
    void update(int ind, int low, int high, int i, int val){
        if(low==high){
            seg[ind] = val;
            return;
        }
        int mid = (low+high)/2;
        if(i<=mid){
            update(2*ind+1,low,mid,i,val);
        }
        else{
            update(2*ind+2,mid+1,high,i,val);
        }
        seg[ind] = seg[2*ind+1]+seg[2*ind+2];
    }
public:
    NumArray(vector<int>& nums) {
        n = nums.size();
        seg.resize(4*n+1);
        build(0,0,n-1,nums);
    }
    
    void update(int index, int val) {
        update(0,0,n-1,index,val);
    }
    
    int sumRange(int left, int right) {
        return query(0,0,n-1,left,right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */