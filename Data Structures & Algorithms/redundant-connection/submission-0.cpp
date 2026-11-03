class UnionFind {
public:
    int count;
    vector<int> root;
    vector<int> rank;

    UnionFind(int n) {
        count = n;
        for (int i = 0; i < n; i++) {
            root.push_back(i);
            rank.push_back(1);
        }
    }

    int find(int u) {
        if (u == root[u]) return u;
        root[u] = find(root[u]);
        return root[u];
    }

    bool Union(int u, int v) {
        int rootU = find(u);
        int rootV = find(v);
        if (rootU == rootV) return false;

        if (rank[rootU] < rank[rootV]) {
            root[rootU] = rootV;
        }
        else if (rank[rootU] > rank[rootV]) {
            root[rootV] = rootU;
        }
        else {
            root[rootU] = rootV;
            rank[rootV] += 1;
        }

        count -= 1;
        return true;
    }
};


class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        UnionFind uf(n);
        for (vector<int>& edge : edges) {
            int from = edge[0] - 1, to = edge[1] - 1;
            if (!uf.Union(from, to)) return edge;
        }
        
        return {};
    }
};
