class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        stack<float> st;  // ✅ float
        int n = position.size();
        vector<pair<int,float>> cars;

        for(int i = 0; i < n; i++)
        {
            float time = (float)(target - position[i]) / speed[i];  // ✅
            cars.push_back({position[i], time});
        }

        sort(cars.begin(), cars.end(), greater<pair<int,float>>());

        for(int i = 0; i < n; i++)
        {
            if(st.empty())
                st.push(cars[i].second);
            else if(cars[i].second <= st.top())
                continue;
            else
                st.push(cars[i].second);
        }

        return st.size();
    }
};