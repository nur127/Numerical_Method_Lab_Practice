#include<bits/stdc++.h>
using namespace std ;
#define nl endl 
#define nur() ios::sync_with_stdio(false);cin.tie(0);
const int N = 1e5 + 5;
const double tolerence = .001;
class RegularFalseMethod
{
private:
    double a, b, c,tolerence ;
    double function(double x){
        // return pow(x, 3) - 2 * x - 5;     //1. example ---> 2.09 ... result --> 2.094568
        // return pow(x, 3)- 5 * x + 3;      //2. exercises ---> 29 ... result --> 0.657
        // return pow(x, 4) + pow(x, 2)- 80; //3. exercises ---> 30 ... result --> 2.908
        // return sinf(x) + x -1;            //4. exercises ---> 28 ... result --> 0.511
        // return x * exp(x) - 1;            //5. example ---> 2.11 ... result --> 0.5671433
        // return x + log10f(x) -2;          //6. exercises ---> 35 ... result --> 1.756
    }

   void randomValueGenerator(){
        srand(time(0));

        do
        {
            a = static_cast<double>(rand())/RAND_MAX * 10 - 5;
            b = static_cast<double>(rand())/RAND_MAX * 10 - 5;
        } while (function(a)*function(b)>=0);
        cout<<"Initial Guess a = "<<a<<" b = "<<b<<nl;
        

    }
public:
    RegularFalseMethod(double tolerence) : tolerence(tolerence){
        randomValueGenerator();
    }

    void solve(){
        int iteration = 1 ; 

        if ( function(a) * function(b) > 0 ){
            cout << "Wrong Guess ! Please Guess Correct Pair."<<nl;
            return;
        }
        while(true){
            c = (a*function(b) - b*function(a)) / (function(b) - function(a));
            cout <<"Iteration: " << iteration << " a: " << a << " b: " << b << "  c: " << c 
                 << "  f(c): " << function(c) << endl;

            if ( abs(function(c)) < tolerence ){
                break;
            }
            if(function(a) * function(c) < 0){
                b = c ;
            }
            else{
                a = c;
            }
            iteration++;
        }
        cout <<"The Root Is : " <<c<<nl;
    }
   
};

int main(){
    nur();
    RegularFalseMethod falsi(tolerence);
    falsi.solve();
    
}