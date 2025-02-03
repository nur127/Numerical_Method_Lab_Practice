#include<bits/stdc++.h>
using namespace std ;
#define nl endl 
#define nur() ios::sync_with_stdio(false);cin.tie(0);
const int N = 1e5 + 5;


void solve(){
    double a,b,c,m,sumX=0,sumY=0,sumXY = 0,sqX = 0;
    cin>>m;
    vector <double>x(m);
    vector <double>y(m);

    for(int i = 0 ; i < m ; i++){
        cin>>x[i]>>y[i];
        sumX +=x[i];
        sumY += y[i];
        sumXY = sumXY + x[i]*y[i];
        sqX += x[i] *x[i];
    }
    double xbar = sumX/m;
    double ybar = sumY/m ;

    b = ((m * sumXY) - (sumX * sumY))/((m*sqX)-(sumX * sumX));
    cout <<b<<nl;
    a = ybar -b *xbar ;
    cout<<a<<endl;
}


int main(){
    nur();
    solve();
}