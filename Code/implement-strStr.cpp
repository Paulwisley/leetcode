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