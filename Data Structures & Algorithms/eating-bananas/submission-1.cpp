class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int minCost = 1;
        int maxCost = *std::max_element(piles.begin(), piles.end());
        int foundCost=maxCost;
        while(minCost <= maxCost){
            int midCost = (minCost + maxCost) / 2;
            long long time{};
            for(int i = 0; i < piles.size(); i++){
                time += ceil(static_cast<double>(piles[i]) / midCost); // ceil div
            }
            if(time <= h){
                maxCost = midCost - 1;
                foundCost = midCost;
            }
            else{
                minCost = midCost + 1;
            }
            
        }
        cout << minCost;
        cout << maxCost;
        return foundCost;
    }
};
