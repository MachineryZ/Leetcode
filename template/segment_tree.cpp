#include <iostream>
#include <vector>

class SegmentTree {
public:
    std::vector<double> sgtree;
    int size;
    SegmentTree(std::vector<double> nums) {
        size = nums.size() * 4;
        // build(0, 0, size, );
    }

    void build(int idx, int l, int r, std::vector<double>& nums) {
        if (l == r) {
            sgtree[idx] = nums[l];
            return;
        }
        int mid = (l + r)/2;
        build(2*idx+1, l, mid, nums);
        build(2*idx+2, mid+1, r, nums);
        return;
    }

    double query(int idx, int q_l, int q_r, int l, int r) {
        if (q_l > r or q_r < l)
            return 0.0;
        }
        if (q_l <= l and r <= q_r) {
            return sgtree[idx];
        }
        int mid = (l + r)/2;
        double ret = 0.0;
        ret += query(2*idx+1, q_l, q_r, l, mid);
        ret += query(2*idx+2, q_l, q_r, mid+1, r);
        return ret;
    }

    void update(int idx, int i, int l, int r, int val) {
        if (l == r) {
            sgtree[idx] = val;
            return;
        }
        int mid = (l + r)/2;
        if (i < mid) {
            update(2*idx+1, i, l, mid, val);
        }
        else {
            update(2*idx+2, i, mid+1, r, val);
        }
        sgtree[idx] = sgtree[2*idx+1] + sgtree[2*idx+2];
        return;
    }
};

/** 
 * TODO 动态开点线段树 需要给线段树创建 4n 的内存 所以节点只有在使用的时候才会创建 单点修改区间查询
 * TODO 猫树
 * TODO 懒惰标记
 * 
*/
