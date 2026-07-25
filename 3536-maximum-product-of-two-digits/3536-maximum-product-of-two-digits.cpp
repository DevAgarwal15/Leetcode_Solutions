class Solution {
public:
    int maxProduct(int n) {
        long long maxi = INT_MIN;
        long long second_maxi = INT_MIN;
        int digit = 0;
        while(n >0){
            digit = n%10;
            if(digit > maxi){
                second_maxi = maxi;
                maxi = digit;
            }
            else if(digit > second_maxi){
                second_maxi = digit;
            }
            n = n / 10;
        }
        return maxi * second_maxi;
    }
};