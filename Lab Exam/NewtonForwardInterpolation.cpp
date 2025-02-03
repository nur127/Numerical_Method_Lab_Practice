#include<bits/stdc++.h>
using namespace std ;
#define nl endl 
#define nur() ios::sync_with_stdio(false);cin.tie(0);
const int N = 1e5 + 5;
class NewtonForwardInterpolation
{
private:
int n;
double x,p,h;
vector<pair<double,double>>v;
vector<vector<double>> del;

int factorial(int x){
    int fact = 1 ;
    for(int i = x ; i > 0 ; i--){
        fact *= i ;
    }
    return fact ;
}

double calcP(double x){
    return (x-v[0].first)/h;
}
void calcDel(){
    del.assign(n,vector<double>(n,0));
    for(int i = 0 ; i < n; i++){
        del[i][0] = v[i].second;
    }
    for(int j = 1 ; j < n ; j++){
        for(int i = 0 ; i < n -j ;i++){
            del[i][j] = del[i+1][j-1] - del[i][j-1] ;
        }
    }
}
    
public:
NewtonForwardInterpolation(vector<pair<double,double>>&q){
    v = q ;
    n = v.size();
    h = v[1].first -  v[0].first ;
    calcDel();
}

double solve(double xx){
 x = xx;
 p = calcP(xx);
 double pTerm = 1.0 ;
 double result = v[0].second;
 for(int i = 1 ; i < n ; i++){
    pTerm *= (p - (i-1));
    result += (pTerm * del[0][i]) /factorial(i);
 }
 return result ;
}
   
};


int main(){
    nur();
    int n;
    cin>>n ;
    double x ;
    cin>>x;

    vector<pair<double,double>>v(n);
    for(int i = 0 ; i < n ; i++){
        cin>>v[i].first>>v[i].second ;
    }
    NewtonForwardInterpolation nft(v);
    double answer = nft.solve(x);
    cout <<answer<<endl;
    
}