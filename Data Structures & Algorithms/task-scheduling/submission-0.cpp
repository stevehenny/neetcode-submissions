class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);
        priority_queue<int> pq;

        for (char t : tasks)
            freq[t - 'A']++;

        for (int f : freq)
            if (f > 0) pq.push(f);

        int time = 0;
        vector<int> temp;

        while (!pq.empty()) {
            int cycle = n + 1;
            temp.clear();

            while (cycle > 0 && !pq.empty()) {
                int cnt = pq.top();
                pq.pop();
                cnt--;
                if (cnt > 0) temp.push_back(cnt);
                time++;
                cycle--;
            }

            for (int val : temp)
                pq.push(val);

            if (pq.empty()) break;

            time += cycle; // idle time
        }

        return time;
    }
};
