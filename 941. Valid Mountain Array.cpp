class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        bool up = true;
        if(arr.size() < 3){
            return false;
        }

        for(int i=0;i<arr.size()-1;i++){
            
            if(up && arr[i] < arr[i+1]){
                continue;
            }else{
                if(i==0){
                    return false;
                }
                up = false;
            }

            if(arr[i]== arr[i+1]){
                return false;
            }

            if(!up && arr[i] > arr[i+1]){
                continue;
            }
            return false;
        }    
        if(up == false){
            return true;
        }else{
            return false;
        }

    }
};