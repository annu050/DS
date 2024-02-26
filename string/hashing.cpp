#include<bits/stdc++.h>
using namespace std;
int p=31;
const int N=1e5+3,m=1e9+7;
vector<long long>powers(N);
long long calculate_hash(string s){
    long long hash=0;
    for(int i=0;i<s.size();i++){// each no * 31^0 then next no 31^1 etc..
        hash=(hash+(s[i]-'a'+1)*powers[i])%m;
    }
    return hash;
}
int32_t main(){
    powers[0]=1;
    for(int i=1;i<N;i++){//0 31 961 29791 ... powers i.e 31^0, 31^1, 31^2 etc.
        powers[i]=(powers[i-1]*p)%m;
    }
    vector<string>s={"aa","ab","aa","b","cc","aa" };
    vector<long long>hashes;
    for(auto w: s){
        hashes.push_back(calculate_hash(w));
    }
    //time complexity:O(nm)
    sort(hashes.begin(),hashes.end());
    //tc:O(n logn)
    //final tc:O(nm +nlog(n))
    int distinct=0;
    for(int i=0;i<hashes.size();i++){
        if(i==0 or hashes[i]!=hashes[i-1]){
            distinct++;
        }
    }
    cout<<distinct<<"\n";
    for(int i=0;i<4;i++){
        cout<<powers[i]<<" ";

    }
}