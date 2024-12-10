#include <iostream>
#include <vector>

#include <iostream>
#include <vector>

class UnionFind {
public:
    UnionFind(int n) : parent(n), rank(n, 0) {
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    // find with path compression
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);  // path compression
        }
        return parent[x];
    }

    // 合并操作，带按秩合并
    void unionSets(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }

    // 判断两个元素是否属于同一个集合
    bool isConnected(int x, int y) {
        return find(x) == find(y);
    }

private:
    std::vector<int> parent;  // parent 
    std::vector<int> rank;    // rank
};