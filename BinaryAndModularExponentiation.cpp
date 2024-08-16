#include<bits/stdc++.h>
using namespace std;
// it is the method of calculating a^n in O(logN) time
// brute force 
long long power(int base,int n){
    long res = 1;
    for(int i=1;i<=n;i++){
        res=res*(long long)base;
    }
    return res;
}

// optimized using binary expo O(logN)  
// for Modular Exponentiation  we modulo it while we were changing base and res 
long long binaryExponentiation(int base,int n,int p){
    int res=1;
    while(n>0){
        if(n%2!=0){ // if odd 
            res=(res*base)%p;
            n=n-1;
        }
        else{
            base=(base*base)%p;
            n=n/2;
        }
    }
    return res;
}

int main(int argc, char const *argv[])
{
    int base,n;
    cin>>base>>n;
    cout<<power(base,n)<<endl;
    cout<<"using binary expo"<<endl;
    int p = 7; // using modular exponentiation -- binary expo modulo some prime number
    cout<<binaryExponentiation(base,n,p)<<"\n";
    return 0;
}
