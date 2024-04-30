#include<bits/stdc++.h>
using namespace std;
void getzal(string str,int z[]){
    int n=str.length();
    int l,r,k;
    l=r=0;
    for(int i=1;i<n;i++){
        if(i>r){
            l=r=i;
            while(r<n && str[r-l]==str[r]){
                r++;
            }
            z[i]=r-l;
            r--;
        }
        else{
            k=i-l;
            if(z[k]<r-i+1){
                z[i]=z[k];
            }
            else{
                l=i;
                while(r<n && str[r-l]==str[r]){
                    r++;
                }
                z[r]=r-l;
                r--;
            }
        }
        
    }
}
void search(string text,string pattern){
    string str=pattern+"$"+text;
    int n=str.length();
    int z[n];
    getzal(str,z);
     for (int i = 0; i < n; ++i)
    {
        // if Z[i] (matched region) is equal to pattern
        // length we got the pattern
        if (z[i] == pattern.length())
            cout << "Pattern found at index "<< i - pattern.length() -1 << endl;
    }

}

int main()
{
    string text = "GEEKS FOR GEEKS";
    string pattern = "GEEK";
    search(text, pattern);
    return 0;
}