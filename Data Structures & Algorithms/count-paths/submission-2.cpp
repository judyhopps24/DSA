class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m==1 || n==1) return 1;
        if(m<n){
            swap(m,n);
        }
        long long int res = 1;
        int j=1;
        for(int i=m;i<=m+n-2;i++){
            res*=i;
            res/=j;
            j++;
        }
        return res;
    }
};
