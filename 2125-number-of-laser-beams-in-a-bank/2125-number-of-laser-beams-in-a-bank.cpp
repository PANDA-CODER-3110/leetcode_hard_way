class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        
        vector<int> num;  // to store the camera cnt at each lvl if cnt>0
        int cnt=0;
			for(int i=0;i<bank.size();i++){  // counting camera at all lvl
            cnt=0;
            for(int j=0;j<bank[0].size();j++){
                if(bank[i][j]=='1'){
                    cnt++;
                }                
            }
            if(cnt>0)  //only need to push if cnt>0
                num.push_back(cnt);
        }
        
        if(num.size()<=1){  //corner case
            return 0;
        }
		
        long long sum=0 ;
        for(int i=0;i<num.size()-1;i++){   // calc final ans
            sum+=(num[i]*num[i+1]);
        }
        
        return sum;
        
    }
};