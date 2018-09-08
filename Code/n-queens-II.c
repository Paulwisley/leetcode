class Solution {
public:
    int count = 0;
    int x[9];
    int totalNQueens(int n) {
        //知乎十行代码版
        /*
        int upperlim = (1 << n) - 1, sum = 0;
        std::function<void(int, int, int)> dfs = [&](int row, int l, int r)
        {
            if(row == upperlim){++sum; return;}
            for(int cur = upperlim&(~(row|l|r)),pos = 0;cur;dfs(row+pos, (l+pos)<<1,(r+pos)>>1))
                {
                    pos = cur & (-cur);
                    cur -=pos;
                }
                
        };
        dfs(0, 0 ,0);
        return sum; 
        */
        //评论版
        backtrack(1,n);
        return count;
    }
    void backtrack(int t,int n)
    {
        if(t>n)
            count++;
        else{
            for(int i=1;i<=n;i++)
            {
                x[t] = i;
                if(place(t))
                    backtrack(t+1,n);
            }
        }
    }
    bool place(int t)
    {
        for(int i=1;i<t;i++)
            if(abs(x[t]-x[i]) == abs(t-i) || x[t] == x[i])
                return false;
        return true;
    }
};
