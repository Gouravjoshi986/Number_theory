#include<iostream>
using namespace std;
int A[101][101];
int I[101][101];  // this is a identity matrix 
// This is the brute force approach with tc of O(M^3 * N)  as multiplication of matrix requires O(M^3) and doign it n times will take O(M^3 * N)

void multiply(int A[][101],int B[][101],int a){
    int res[a+1][a+1];        // this is multiplication of matrix 
    for(int i=1;i<=a;i++){
        for(int j=1;j<=a;j++){
            res[i][j]=0;
            for(int k=1;k<=a;k++){
                res[i][j]+=(A[i][k]*B[k][j]);
            }
        }
    }

    for(int i=1;i<=a;i++){
        for(int j=1;j<=a;j++){
            A[i][j]=res[i][j];
        }
    }
}

void power(int mat[][101],int a,int n){
    for(int i=1;i<=a;i++){
        for(int j=1;j<=a;j++){
            if(i==j)I[i][j]=1;
            else I[i][j]=0;
        }
    }
    // initialised identity matrix 
    // for(int i=1;i<=n;i++){     // this is normal matrix multiplication 
    //     multiply(I,A,a);  // I = I * A 
    // }
    
    while(n){
        if(n%2){  // odd 
            multiply(I,A,a);
            n--;                 // this is matrix exponentiation. TC = O(M^3 * logN)
        }
        else{
            multiply(A,A,a);
            n=n/2;
        }
    }

    for(int i=1;i<=a;i++){
        for(int j=1;j<=a;j++){
            mat[i][j]=I[i][j];    // storing answer in matrix instead of I 
        }
    }
}
int main(int argc, char const *argv[])
{
    int a,n;
    cin>>a>>n;
    for(int i=1;i<=a;i++){
        for(int j=1;j<=a;j++){
            cin>>A[i][j];
        }
    }
    
    power(A,a,n);

    for(int i=1;i<=a;i++){
        for(int j=1;j<=a;j++){
            cout<<A[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
