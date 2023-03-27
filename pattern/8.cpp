#include<bits/stdc++.h>
using namespace std;
int main(){
    int i,j,n;
    cin>>n;
    //3               //3           //3
    //AAA             //ABC         //ABC   i=0;
    //BBB             //DEF         //BCD  'A'+(i+j)-1;
    //CCC             //GHI         //CDE
    i=1;
    //2   char ch1='A'; AND i=0
    while(i<=n){
        
        char ch1='A'+i-1;
        for(j=1;j<=n;j++){
            
            cout<<ch1;
           //2   ch1++;
                 
        }
   cout<<endl;
   i++;
    }
}