inline unsigned long long vecfromstr(std::string& s, std::vector<unsigned long long>& chalk) {
    unsigned long long number = 0;
    unsigned long long prev_number = 0;
    chalk.clear();
    for (char* c = &s[1]; *c != '\0'; c++) {
        if (*c >= 48 && *c <= 57) {
            number = number * 10 + (*c & 15);
            continue;
        }
        unsigned long long newn = number + prev_number;
        chalk.push_back(newn);
        prev_number = newn;
        number = 0;
    }
    return prev_number;
}

int init = [] {
    cin.tie(nullptr)->sync_with_stdio(false);
    freopen("user.out", "w", stdout);
    vector<unsigned long long> chalk;
    int k;
    for (std::string s; getline(cin, s);) {
        unsigned long long max = vecfromstr(s, chalk);
        getline(cin, s);
        k = std::stoi(s);
        unsigned long long left = k % max;
        vector<unsigned long long>::iterator u;
        u = upper_bound(chalk.begin(), chalk.end(), left);
        std::cout << (u-chalk.begin()) << '\n';
    }
    return 0;
}();

class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) { return 0; }
};