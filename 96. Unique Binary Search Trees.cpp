class Solution {
public:
    vector<vector<int>> memo;
    int numTrees(int n) {
        memo = vector<vector<int>>(n+1, vector<int>(n+1, 0));
        return num(1, n);
    }
    int num(int a, int b){
        if( a>=b ) return 1;
        if(memo[a][b] != 0) return memo[a][b];
        for(int i = a;i <= b;++i){
            memo[a][b] += num(a, i-1) * num(i+1, b);
        }
        return memo[a][b];
    }
};
class Solution {
public:
    vector<int> memo;
    int numTrees(int n) {
        memo = vector<int>(n+1, 0);
        return num(n);
    }
    int num(int n){
        if( n == 1 || n == 0 ) return 1;
        if(memo[n] != 0) return memo[n];
        for(int i = 1;i <= n;++i){
            memo[n] += num(i-1) * num(n-i);
        }
        return memo[n];
    }
};