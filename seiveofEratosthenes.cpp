#include<iostream>
using namespace std;

// sieve is implemented to precompute the values of isprime to find prime till a range 
// its logic is based on removing all multiples of occuring primes in the iteration 
// we have iterated from i = 2 till the i = sqrt(N) as we will mark from the square of i till the maxN for multiples . This is due to the fact that all values before  

// TC = O(NloglogN)  this will remain same for all optimizations 
//  brute = running seive till n 
// optimized = running seive till sqrtN 
// further optimization = running seive for only odd numbers as all even numbers except 2 
// are not prime.   -- can save half memory and reduce no of iterations by half 
 
bool isPrime[10000001];

void seive(){
    int maxN=1000000;
    for(int i=1;i<=maxN;i++){
        if(i>2 && i%2==0)isPrime[i]=0;
        else isPrime[i]=1;
    }
    isPrime[0]=isPrime[1]=0;

    for(int i=2;i*i<=maxN;i++){
        if(i>2 && i%2==0)continue;

        if(isPrime[i]){
            for(int j=i*i;j<=maxN;j+=i){
                isPrime[j]=0;
            }
        }
    }
}
int main(int argc, char const *argv[])
{   
    seive();
    cout<<"is 7 Prime: "<<isPrime[7]<<"\n";
    cout<<"is 10 Prime: "<<isPrime[10]<<"\n";
    cout<<"is 15 Prime: "<<isPrime[15]<<"\n";
    return 0;
}
