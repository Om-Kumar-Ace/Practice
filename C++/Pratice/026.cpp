int minimumSortedGroups(int n, vector<int> arr) {
    vector<set<int>> groups;
    for (int num : arr) {
        bool inserted = false;
        for (auto &group : groups) {
            if (*group.rbegin() <= num) {
                group.insert(num);
                inserted = true;
                break;
            }
        }
        if (!inserted) {
            set<int> newGroup;
            newGroup.insert(num);
            groups.push_back(newGroup);
        }
    }
    return groups.size();
}