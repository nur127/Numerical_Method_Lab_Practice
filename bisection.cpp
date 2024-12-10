#include<bits/stdc++.h>
using namespace std ;
#define nl endl 
#define nur() ios::sync_with_stdio(false);cin.tie(0);
const int N = 1e5 + 5;
const double eta = .001;

double equation(double x){
   
    return pow(x,3) - (2*x) - 5;
    // return pow(x,3) - x -1 ;
}

void solve(double a, double b){
    double c;
    // cout <<equation(a) <<" " <<equation(b)<<nl;
    if(equation(a) * equation(b) > 0){
        cout <<"Your Guess Are Wrong . Please Guess Another Pair";
        return;
    }
    
    else{
        int i = 1;
        while(true){
            

            c = ((a+b) /2.0);
            cout<<"Itaretion : " << i <<" " <<" a : "<<a<<" b :" <<b<<" c : " <<c<< " f(c)----> "<<equation(c)<<nl;
             i++;
            if(abs(equation(c)) < eta){
                break;
            }
           
            if(equation(a) * equation(c) < 0 ){
                b = c;
                 
            }
            else{
                a = c ;
               
            }
           
        }
        cout<<nl <<"The Root is : " << setprecision(4)<<c<< nl;
    }
}

int main(){
    nur();
    double a,b;
    cin>>a>>b;
    solve(a,b);
}