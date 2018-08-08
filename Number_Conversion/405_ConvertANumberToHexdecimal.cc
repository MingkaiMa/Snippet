class Solution {
public:
string toHex(int num) {
        if(num == -2147483648)
            return "80000000";
        unordered_map<int, char> Map;
        for(int i = 0; i < 10; ++i){
            Map[i] = '0' + i;
        }
        
        Map[10] = 'a';
        Map[11] = 'b';
        Map[12] = 'c';
        Map[13] = 'd';
        Map[14] = 'e';
        Map[15] = 'f';
        
        if(num == 0)
            return "0";
        if(num > 0){
            string res = "";
            while(num){
                res += Map[num % 16];
                num = num / 16;
            }
            reverse(res.begin(), res.end());
            return res;
        }

        int n = num * (-1);
        
        string binaryNb = "";
        
        while(n){
            binaryNb += to_string(n % 2);
            n = n / 2;
        }
        
        
        int i = binaryNb.size();
        for(; i < 32; ++i){
            binaryNb += "0";
        }

        for(int j = 0; j < binaryNb.size(); ++j){
            if(binaryNb[j] == '0')
                binaryNb[j] = '1';
            else
                binaryNb[j] = '0';
        }

        int carry = 1;
        for(int j = 0; j < binaryNb.size(); ++j){
            if(binaryNb[j] == '0'){
                if(carry == 1){
                    binaryNb[j] = '1';
                    carry = 0;
                }
            }
            else{
                if(carry == 1){
                    binaryNb[j] = '0';
                    carry = 1;
                }
            }
        }
        
        
        
        reverse(binaryNb.begin(), binaryNb.end());

        int index = 0;
        string res = "";
        
        while(index < 32){
            string strSub = binaryNb.substr(index, 4);
            index += 4;
            
            int nn = 0;
            int bit = 0;
            for(auto it = strSub.rbegin(); it != strSub.rend(); it++){
                if(*it == '1'){
                    nn = nn + pow(2, bit);
                }
                ++bit;
            }
            

            res += Map[nn];
        }
        
        return res;
    }
};
