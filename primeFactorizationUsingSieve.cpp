// by using sieve we can do prime factorization in logn time 
#include<iostream>
using namespace std;
int arr[1000001];

void sieve(){
    int maxN = 1000000;
    for(int i=1;i<=maxN;i++){arr[i]=-1;}
    for(int i=2;i<=maxN;i++){
        if(arr[i]==-1){
            for(int j=i;j<=maxN;j+=i){
                if(arr[j]==-1)arr[j]=i;
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    sieve();
    int n;
    cin>>n;

    while(arr[n]!=-1){
        cout<<arr[n]<<" ";
        n=n/arr[n];
    }
    return 0;
}
