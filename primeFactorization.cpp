#include<iostream>
#include<vector>
using namespace std;

void primeFactor(int n,vector<pair<int,int>>&ans){
    for(int i=2;i<=n;i++){
        if(n%i==0){
            int cnt=0;
            while(n%i==0){
                cnt++;
                n=n/i;
            }
            ans.push_back({i,cnt});
        }
    }
}
// brute force would be using a counter on whole 1 to n and whenever we find a number which divides we find its power using another loop 
// TC - the inner loop will run for logn time and the outer loop for any non prime no will 
// at most run for 10 times. so it is near constant. In case of prime numbers the loop can 
// run for o(N) time as no prime will divide it. 

void primeFactorBetter(int n,vector<pair<int,int>>&ansBetter){
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            int cnt=0;
            while(n%i==0){
                cnt++;
                n=n/i;
            }
            ansBetter.push_back({i,cnt});
        }
    }
    if(n>1)ansBetter.push_back({n,1});
}
// optimized approach - run loop till sqrtN (as one of the factors will be below sqrtN and one above)

int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    vector<pair<int,int>>ans;
    vector<pair<int,int>>ansBetter;
    primeFactor(n,ans);
    primeFactorBetter(n,ansBetter);

    for(auto it:ans){
        cout<<it.first<<"^"<<it.second<<" ";
    }
    cout<<endl;

    for(auto it:ansBetter){
        cout<<it.first<<"^"<<it.second<<" ";
    }
    return 0;
}
