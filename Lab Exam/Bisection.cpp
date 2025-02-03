#include<bits/stdc++.h>
using namespace std ;
#define nl endl 
#define nur() ios::sync_with_stdio(false);cin.tie(0);
const int N = 1e5 + 5;
const double tolerence = .0001 ;

class Bisection
{
private:
double a,b,c,tolerence;

double function(double x){
    return pow(x,4) - x -10;
}
void randomValueGenarate(){
    srand(time(0));

 do
 {
    a = static_cast<double>(rand()) / RAND_MAX*20;
    b = static_cast<double>(rand()) / RAND_MAX*20;
 } while (function(a)*function(b) >=0);
  cout <<"Initial Guess - a : " << a  <<" b : " <<b <<endl;
 
}
   
public:
Bisection (double tol){
tolerence = tol ;
randomValueGenarate();
}
void solve(){
    int it = 1 ;
    if(function(a) * function(b) > 0 ){
        cout <<"Wrong Guess ! Please Guess Again"<<endl;
    }

    else{
        while (true)
        {
            cout<<"Iteration : " <<it <<" Value of a : " <<a <<" Value of b : " << b <<endl;
            c = (a+b) / 2.0 ;
            if(abs(function(c)) < tolerence){
                break;
            }
            else if (function(a) * function(c) < 0){
                b = c ;
            }
            else{
                a = c ;
            }
            it++;
        }
        cout <<"Answer is : " <<setprecision(4)<<c<<endl;
        
    }
}
  
};

int main(){
    nur();
    Bisection bisection(tolerence);
    bisection.solve();
    
}