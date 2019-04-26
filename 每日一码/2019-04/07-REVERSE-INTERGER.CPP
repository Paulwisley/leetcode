    #include "../INCLUDE/GLOBAL.H"
    int reverse(int x) {
        std::ios::sync_with_stdio(NULL);
        std::cin.tie(NULL);
        std::cout.tie(NULL);
        if(x>=INT_MAX || x <=INT_MIN) return 0;
        int tmp = abs(x);
        int ans = 0;
        while((tmp / 10)){
            int cur = tmp % 10;
            tmp = tmp / 10;
            ans = cur + ans * 10;
        }
        if(ans > INT_MAX/10) return 0; 
        ans = tmp + ans * 10;
        return (x > 0) ? ans : -ans;
    }
    
    /*
    整体算法思想比较容易想到和实现，但是有一些细节需要注意：
    这里的int 翻转之后 原本不溢出的值 发生上溢或者下溢
    因为这里先取了绝对值 所以统一做上溢处理
    拿 ans 和 INT_MAX/10 做比较
    还有一些比较便捷的判断是否发生溢出的处理办法：加减法中，可以先做运算(如加)，然后再做相应的逆运算(如减)
    此时若数值和原始数值不等，则发生溢出
    */