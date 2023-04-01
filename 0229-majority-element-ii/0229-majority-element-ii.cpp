class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int count = 0 ,num1 =-1 , num2 =-1 , count1 =0 ; ; 
        for(int i= 0; i<nums.size();i++)
        {
           if(num1== nums[i])
               count++;
            else if(num2==nums[i])
            {
                count1++;
            }
          else if(count ==0)
           {
               count++;
               num1=nums[i];
           }
            else if(count1==0)
            {
                count1++;
                num2=nums[i];
            }
            else
            {
                count-- ; 
                count1-- ; 
            }
        }
        vector<int>ans ;
        count1 =0 , count =0  ;
         for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == num1)
                count++;
            else if (nums[i] == num2)
                count1++;
        }
        if(count>nums.size()/3)
            ans.push_back(num1); 
        
         if(count1>nums.size()/3)
            ans.push_back(num2); 
            
        
        return ans ; 
    }
};