class Disjoint {
public:
    vector<int> size, parent;
    Disjoint(int n) {
        for(int i = 0; i <= n; ++i) {
            size.push_back(1);
            parent.push_back(i);
        }
    }

    int findPar(int node) {
        if(node == parent[node]) return node;
        return parent[node] = findPar(parent[node]);
    }

    void unionn(int a, int b) {
        a = findPar(a);
        b = findPar(b);

        if(a == b) return;
        if(size[a] < size[b]) {
            parent[a] = b;
            size[b] += size[a];
        } else {
            parent[b] = a;
            size[a] += size[b];
        }
    }
};
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();

        int maxRow = 0, maxCol = 0;
        for(int i = 0; i < n; ++i) {
            maxRow = max(maxRow, stones[i][0]);
            maxCol = max(maxCol, stones[i][1]);
        }

        Disjoint *dsu = new Disjoint(maxRow + maxCol + 1);

        for(int i = 0; i < n; ++i) {
            int col = stones[i][1];
            int row = stones[i][0] + maxCol + 1;
            dsu -> unionn(row, col);
        } 
        set<int> numComp;
        for(int i = 0; i < n; ++i) {
            int row = stones[i][0] + maxCol + 1;
            int col = stones[i][1];
            numComp.insert(dsu -> findPar(row));
            numComp.insert(dsu -> findPar(col));
        }

        return n - (int)numComp.size();

    }
};