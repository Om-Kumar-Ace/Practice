char speedUp = [] {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 'z';
}();

class MyCalendar {
    struct Node {
        int start, end;
        Node(int start, int end) : start(start), end(end) {}
        bool operator<(const Node& other) const { return other.start >= end; }
    };
    set<Node> s;

public:
    MyCalendar() {}

    bool book(int start, int end) {
        auto it = s.lower_bound({start, end});
        if (it != s.end() && it->start < end)
            return false;
        s.insert({start, end});
        return true;
    }
};