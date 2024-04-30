class Solution {
public:
    long long wonderfulSubstrings(string word) {
        unordered_map<int,int>count;
        int mask=0;
        count[0]=1;//cumilative at star xor is 1 for 000
        long long res=0;
        for(char c:word){
            mask^=1<<(c-'a');
            res+=count[mask];//add ki kitne baar past mein dekha hai i.e ch is even in count
            for(int i=0;i<10;i++){
                res+=count[mask^(1<<i)];//xor with a,b,c,....j tak to check
            }
            count[mask]++;
        }
        return res;
    }
};