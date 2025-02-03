#include<bits/stdc++.h>
using namespace std ;
#define nl endl 
#define nur() ios::sync_with_stdio(false);cin.tie(0);
const int N = 1e5 + 5;
const double tolerence = .0001;

class Bisection
{
private:

    double a,b,c,tolerence;

    double function(double x){
        return pow(x, 3) - 2 * x - 5;     //1. example ---> 2.09 ... result --> 2.094568
        // return pow(x, 3)- 5 * x + 3;      //2. exercises ---> 29 ... result --> 0.657
        // return pow(x, 4) + pow(x, 2)- 80; //3. exercises ---> 30 ... result --> 2.908
        // return sinf(x) + x -1;            //4. exercises ---> 28 ... result --> 0.511
        // return x * exp(x) - 1;            //5. example ---> 2.11 ... result --> 0.5671433
        // return x + log10f(x) -2;          //6. exercises ---> 35 ... result --> 1.756
        // return 3*pow(x,3) + 4 * pow(x,2) + 5*x + 16;
    }

    void randomGenarator(){
        
        srand(time(0));
        do
        {
            a = static_cast<double>(rand())/RAND_MAX * 20 - 10;
            b= static_cast<double>(rand())/RAND_MAX *20 - 10;
        } while (function(a) * function(b) >=0);

        cout << "Initial Guess : a = " << a <<" b =  " <<b<<nl;
        
    }
  
public:

    Bisection(double tolarence) : tolerence(tolarence){
        randomGenarator();
    }

    void solve(){
        if(function(a) * function(b) > 0){
            cout<<"Failed to find a bracketing interval. Try again." << endl;
            return;
        }
        double c;
        int iteration = 1;
        while (true) {
            c = (a + b) / 2.0;
            cout << "Iteration: " << iteration << " a: " << a << " b: " << b << "  c: " << c 
                 << " | f(c): " << function(c) << endl;

            if (abs(function(c)) < tolerence) {
                break;
            }

            if (function(a) * function(c) < 0) {
                b = c;
            } else {
                a = c;
            }
            iteration++;
        }
        cout <<nl<<nl<< "The root is: " << fixed << setprecision(4) << c << endl;
    }
    
};

int main(){
    nur();
    Bisection bisection(tolerence);
    bisection.solve();
    
}









