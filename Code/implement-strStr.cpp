#include<string>
using namespace std;

int strStr(string haystack, string needle) {
       int hayLength = haystack.size();
       int needleLength = needle.size();
       int hayIndex = 0;
       int needleIndex = 0;
       if(needle.empty())
           return 0;
       //use a slip window to maintain the index
       while(hayIndex < hayLength){
       		if(haystack[hayIndex] == needle[needleIndex]){
       			++hayIndex;
       			++needleIndex;
       		}
       		else{
       			hayIndex = hayIndex - needleIndex + 1;
       			needleIndex = 0;
       		}	
           if(needleIndex == needleLength)
       			return hayIndex - needleLength;
       }
       return -1;
}

//一重循环 没有用什么KMP  感觉路子也是非常野了 用加锁的方法 配合指针维护第一次匹配到的首字母
char *strStr(char *haystack, char *needle) {
    int hayLength = strlen(haystack);
    int needleLength = strlen(needle);
    char *hayIndex = haystack;
    char *tmp = hayIndex;
    char *needleIndex = needle;
    int lock = 0;
    if(needleLength == 0)
        return haystack;
    //use a slip window to maintain the index
    while(*hayIndex != '\0'){
        if(*hayIndex == *needleIndex){
            if(!lock){
                tmp = hayIndex;
                lock = 1;
            }
            hayIndex++;
            needleIndex++;
        }
        else{
            hayIndex = ++tmp;
            needleIndex = needle;
            lock = 0;
        }
        if(*needleIndex == '\0')
            return tmp;
    }
    return nullptr;
}
