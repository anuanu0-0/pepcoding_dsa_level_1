#include<iostream>
using namespace std;

int powerLogarithmic(int x,int n){
    if(n<=0)  return 1;

    int pow = powerLogarithmic(x, n/2);

    if(n%2==0)
        return pow*pow;
    else 
        return x*pow*pow;
}

int main(){
    int x,n; cin>>x>>n;
    cout<<powerLogarithmic(x,n);
}