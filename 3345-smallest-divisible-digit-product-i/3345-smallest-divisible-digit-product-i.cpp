class Solution {
public:

    int digitproduct(int x){
        int product = 1;
        while(x){
            product *= x % 10;
            x /= 10;
        }
        return product;
    }
    int smallestNumber(int n, int t) {
        while(true){
            if(digitproduct(n)%t == 0){
                return n;
            }
            n++;
        }
        return -1;
    }
};