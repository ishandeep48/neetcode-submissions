class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> hmap;

    TimeMap() {}

    void set(string key, string value, int timestamp) {

        hmap[key].push_back({timestamp, value});

        return;
    }

    string get(string key, int timestamp) {

        const auto& temp = hmap[key];
        int max_before = -1;
        int start = 0;
        int end = temp.size() - 1;
        while (start <= end) {
            int middle = start + (end - start) / 2;
            int curr_time = temp[middle].first;
            if (curr_time == timestamp) {
                return temp[middle].second;
            } else if (curr_time < timestamp) {
                start = middle + 1;
            } else {
                end = middle - 1;
            }
        }
        if (end == -1) return "";
        return temp[end].second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */