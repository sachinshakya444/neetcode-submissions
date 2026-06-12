class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        stack <float> st;
        int n = position.size();
        vector <float> time;
        vector <pair<int,float>> cars;
        for(int i=0;i<n;i++)
        {
            time.push_back((float)(target-position[i])/speed[i]);
            cars.push_back({position[i],time[i]});
        }
        sort(cars.begin(),cars.end(),greater<pair<int,float>>());
        for(int i=0;i<n;i++)
        {
            if(st.empty())
            st.push(cars[i].second);
            else if(cars[i].second<=st.top())
            continue;
            else
            st.push(cars[i].second);
        }
        return st.size();
    }
};
