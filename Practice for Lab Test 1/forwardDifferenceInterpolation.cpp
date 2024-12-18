#include<bits/stdc++.h>
using namespace std;

class forwardDifferenceInterpolation
{
private:
    double x,p,h;
    int n ;
    vector<pair<double,double>>v;
    vector<vector<double>>del;
    int factorial(int x){
        int fact = 1 ;
        for(int i = x ; i > 0 ; i--){
            fact *= i ;
        }
        return fact ;
    }
    double calcPvalue(double x,double x0){
        return (x-x0)/h ;
    }
    void calcDel(){
        del.assign(n,vector<double>(n,0));
        for(int i = 0 ; i < n ;i++){
            del[i][0] = v[i].second;
        }
        for(int j = 1 ; j < n ; j++){
            for(int i = 0 ; i < n-j ; i++ ){
                del[i][j] = del[i+1][j-1] - del[i][j-1];
            }
        }
    }
public:
forwardDifferenceInterpolation(vector<pair<double,double>> &vec){
    v = vec ;
    n = v.size();
    h = v[1].first - v[0].first ;
    calcDel();
}

double solve(double xx){
    x = xx;
    double pValue = calcPvalue(xx,v[0].first);
    double result = v[0].second;
    double pT = 1.0 ;
    for(int i = 1 ; i < n ; i++){
        pT *= (pValue - (i-1));
        result += (pT*del[0][i])/factorial(i);
    }
    return result;
}

};

int main(){
    int n ;
    double x;
    cin>>n;
    cin>>x;

    vector<pair<double,double>> v(n);
    for(int i = 0 ; i < n ; i++){
        cin>>v[i].first>>v[i].second;
    }
    forwardDifferenceInterpolation fdi(v);
    double result = fdi.solve(x);
    cout<<result<<endl;
}