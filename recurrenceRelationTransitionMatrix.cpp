#include<iostream>
using namespace std;

// the transition matrix is a matrix which on multiplying by a recurrence relation will change the values to another. 
// [f1 f2] * [Transition matrix]^1 = [f2 f3]
// we can mark it as [a b / c d]  and making it using eqn 
// f1.A + f2.c = f2 , f1.b + f2.d = f3 so c=1 a=0 b=1 d=1 as f3=f1+f2  
// so For Fibonacci sequence Transition matrix =  [ A B ]  =  [0 1]
//                                                [ C D ]     [1 1]

// now we can use matrix exponentiation to find fibonacci nth sequence in logN time
// [f1 f2] * [matrix]^n-1 = [fn fn+1] 
void multiply(int A[][2],int B[][2]){
    int res[2][2];
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            res[i][j]=0;
            for(int k=0;k<2;k++){
                res[i][j]+=A[i][k]*B[k][j];
            }
        }
    }

    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            A[i][j]=res[i][j];
        }
    }
}
void power(int B[][2],int n){
    int I[2][2] = {{1,0},{0,1}};

    while(n){
        if(n%2){    // odd      // i = i*b 
            multiply(I,B);
            n--;
        }
        else{
            multiply(B,B);
            n=n/2;
        }
    }

    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            B[i][j]=I[i][j];
        }
    }
}
int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    
    int A[2] = {1,1};
    int B[2][2] = {{0,1},{1,1}};
    // now using matrix expo - B^(n-1) 
    power(B,n-1);  // b matrix
    // now  nth number is A[0].b[0][0] + A[1].b[1][0]
    int third = (A[0]*B[0][0])+(A[1]*B[1][0]); 
    cout<<third<<endl;

    return 0;
}
