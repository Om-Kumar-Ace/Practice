static const int _ = []{cin.tie(0);ios::sync_with_stdio(0);return 0;}();
class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<double> prob(n); prob[start_node] = 1.0;
        for (int i = 0; i < n; ++i) {
            bool connected = false;
            for (int j = 0; j < edges.size(); ++j) {
                int a = edges[j][0], b = edges[j][1];
                double p = succProb[j];
                if (prob[a]*p > prob[b]) {
                    prob[b] = prob[a]*p;
                    connected = true;
                }
                if (prob[b]*p > prob[a]) {
                    prob[a] = prob[b]*p;
                    connected = true;
                }
            }
            if (!connected) break;
        }
        return prob[end_node];
    }
};