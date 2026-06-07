class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector <int> product1;
        vector <int> product2;
        vector <int> product;
        int result=1;
        for(int i=0;i<nums.size();i++)
        {
            if(i==0)
            product1.push_back(1);
            else
            {
            result=result*nums[i-1];
            product1.push_back(result);
            }
        }
        result=1;
        for(int i=nums.size()-1;i>=0;i--)
        {
            if(i==(nums.size()-1))
            product2.push_back(1);
            else
            {
            result=result*nums[i+1];
            product2.push_back(result);
            }
        }
        reverse(product2.begin(), product2.end());
        for(int i=0;i<nums.size();i++)
        {
            product.push_back((product1[i] * product2[i])); 
        }
        
        return product;

    }
};
