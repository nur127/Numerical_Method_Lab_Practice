#include<bits/stdc++.h>
using namespace std ;
#define nl endl 
#define nur() ios::sync_with_stdio(false);cin.tie(0);
const int N = 1e5 + 5;

double func(double x){
    return 1/x;

}

void solve(double n,double b , double a){
    int i =1;
    double delX,x,ans=0;

    delX = (b-a)/(double)n;

   ans = ((func(a) + func(b))/2.0);
    
    while(i < n){

        x = a + i*delX;
        ans += func(x);
        i++;

     }
    cout<<fixed<<setprecision(6)<<ans*delX<<endl;
}

int main(){
    nur();
    double n ,b,a;
    cin>>n>>b>>a;
    solve(n,b,a);
}