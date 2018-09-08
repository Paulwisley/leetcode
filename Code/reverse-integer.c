int reverse(int x) {
	        long absRe=0;
	        int tmp=abs(x);
	        while(tmp)
	        {
	            absRe = absRe * 10 + tmp % 10;
	            tmp/=10;
	        }
	        if(isOverflow(absRe))
	                return 0;
	        absRe = (int)absRe;
	        return x >= 0 ? absRe:-absRe;   
	    }
//重点是要记得判断是否有溢出    
bool isOverflow(long x){
	        if(x > 0){
	            if(x > 0x7fffffff)
	                return true;
	        }
	        else{
	            if(x < 0x80000000)
	                return true;
	        }      
	        return false;
	    }
