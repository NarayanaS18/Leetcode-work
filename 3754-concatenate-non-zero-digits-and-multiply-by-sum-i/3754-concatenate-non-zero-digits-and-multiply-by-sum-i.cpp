class Solution {
public:
    long long sumAndMultiply(int n) {
        int temp = n;
        long long ans = 0;
        int dig = 1;
        while(temp > 0){
            int rem = temp % 10;       
            if(rem != 0){
                ans += rem*dig;
                dig *= 10;
            }

            temp = temp/10;
        }
        long long temp2 = ans;
        int sum = 0;
        while(temp2 > 0){
            int rem = temp2 % 10;
            sum += rem;
            temp2 = temp2/10;
        }

        return ans*sum;
    }
};