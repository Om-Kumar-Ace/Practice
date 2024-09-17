#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/priority_queue.hpp>
using namespace std;
using namespace __gnu_pbds;

inline namespace skyly {
    /* default c++ template for problem solving */
#ifdef LOCAL_DEBUG
    #include <dbg.h>
#else
    #define dbg(...) 77
#endif

    #define rep(i, n_rep) for (decay_t<decltype(n_rep)> i = 0; i < (n_rep); ++i)
    #define ffor(i, begin_i, end_i) for (decay_t<decltype(end_i)> i = (begin_i); i < (end_i); ++i)
    #define rfor(i, begin_i, end_i) for (decay_t<decltype(end_i)> i = (end_i) - 1; i >= (begin_i); --i)
    #define sz(x) int((x).size())
    #define all(x) begin(x), end(x)
    #define rall(x) rbegin(x), rend(x)
    #define each(x, lst) for (auto& x : lst)
    #define eachp(x, y, lst) for (auto& [x, y] : lst)

    mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

    using I = int64_t;
    using U = uint64_t;
    using F = long double;
    using S = string;
    template <class T1, class T2> using P = pair<T1, T2>;
    template <class T> using V = vector<T>;
    template <class T, class Cmp = less<T>> using Set = tree<T, null_type, Cmp, rb_tree_tag, tree_order_statistics_node_update>;
    template <class T1, class T2, class Cmp = less<T1>> using Map = tree<T1, T2, Cmp, rb_tree_tag, tree_order_statistics_node_update>;
    template<class T, class Cmp = less<T>> using pqueue = std::priority_queue<T, vector<T>, Cmp>;
    template<class T, class Cmp = less<T>> using Heap = __gnu_pbds::priority_queue<T, Cmp>;

    struct CustomHash {
        static U splitmix64(U x) {
            x += 0x9e3779b97f4a7c15;
            x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
            x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
            return x ^ (x >> 31);
        }
        size_t operator()(U x) const noexcept {
            static const U FIXED_RANDOM = rng();
            return splitmix64(x + FIXED_RANDOM);
        }
        template<typename T> size_t operator()(const P<T, T>& x) const {
            return (*this)(U(x.first)) ^ ((*this)(U(x.second)) >> 1);
        }
    };
    template <class T> using HashSet = gp_hash_table<T, null_type, CustomHash>;
    template <class T1, class T2> using HashMap = gp_hash_table<T1, T2, CustomHash>;

    template <typename T, T val = T(), typename... Args>
    auto make_vector(size_t x, Args... arr) {
        if constexpr (sizeof...(arr) == 0) return V<T>(x, val);
        else return vector(x, make_vector<T, val>(arr...));
    }

    inline namespace misc_defines {
        constexpr auto ssort = ranges::sort;
        template <typename T> using nlim = numeric_limits<T>;
        template <typename T, typename F = less<T>> void sort_unique(V<T>& v, F f = F()) { sort(all(v), f); v.resize(unique(all(v)) - begin(v)); }
        template <typename T> constexpr T sum(const V<T>& v) { return v.empty() ? T(0) : accumulate(v.cbegin(), v.cend(), T(0)); }
        template <typename T> constexpr bool chmax(T& a, const T& b) noexcept { return b > a ? a = b, true : false; }
        template <typename T> constexpr bool chmin(T& a, const T& b) noexcept { return b < a ? a = b, true : false; }
        template <typename T> constexpr T has_bit(T x, int i) noexcept { return x & (T(1) << i); }
        template <typename T> constexpr int log2_floor(T x) noexcept { static_assert(is_integral_v<T>);
            if (x <= T(0)) return -1;
            if constexpr (nlim<T>::digits <= nlim<unsigned int>::digits) return nlim<unsigned int>::digits - __builtin_clz(x) - 1;
            else return nlim<U>::digits - __builtin_clzll(x) - 1;
        }
        template <typename T> constexpr int log2_ceil(T x) noexcept { return log2_floor(x - 1) + 1; }
        constexpr F PI = numbers::pi_v<F>;
        constexpr int F_OUTPUT_PRECISION = 20;
    }
}
/* main part of the solution starts from here */

inline namespace solution_space {
/* begin */
bool to_init = true;

class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        auto build = [](S& str) {
            istringstream ssin(str);
            map<S, int> occ; S s;
            while (ssin >> s) occ[s]++;
            return occ;
        };
        map<S, int> occ;
        eachp (s, socc, build(s1)) occ[s] += socc;
        eachp (s, socc, build(s2)) occ[s] += socc;
        V<S> ans;
        eachp (s, socc, occ) if (socc == 1) ans.push_back(s);
        return ans;
    }
};
/*  end  */
}

#ifdef LOCAL_DEBUG
int main() {
    dbg("Ready to go...");
    Solution s;
    dbg("Program finished normally.");
    return 0;
}
#endif