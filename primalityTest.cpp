#include<iostream>
using namespace std;

// for checking if a number is a prime number or not we use the primality test 
// brute    -- TC - O(N)
bool checkPrime(int n){
    if(n==1)return false;
    for(int i=2;i<n;i++){
        if(n%i==0)return false;
    }
    return true;
}
// better tc = O(sqrt(N))
bool checkPrimeBetter(int n){
    if(n==1)return false;
    for(int i=2;i*i<n;i++){
        if(n%i==0)return false;
    }
    return true;
}
// the logic is that for any number the divisors occur in pair ie (a,b)  now for this to be true one should be less than sqrt(n) and one should be greater than sqrt(n). 
// so we only check till sqrt(n) 
int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    cout<<checkPrime(n)<<endl;
    cout<<checkPrimeBetter(n)<<endl;
    return 0;
}
 