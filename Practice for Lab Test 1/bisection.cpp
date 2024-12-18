#include<bits/stdc++.h>
using namespace std;
const double tol =.0001;

class Bisection
{
private:
    double a,b,c,tolerence;

    double function(double x){
        return pow(x, 3) - 2 * x - 5; 
    }
    void randomValueGenerator(){
        srand(time(0));
        do
        {
           a =static_cast<double>(rand())/RAND_MAX *20-10;
           b =static_cast<double>(rand())/RAND_MAX *20-10;
        } while (function(a)*function(b)>=0);

        cout << "Initial Guess of a : "<<a <<" and b : "<<b<<endl;
        
    }
public:
Bisection (double tol){
    tolerence = tol ;
    randomValueGenerator();
}

void solve (){
     int iteration = 1 ;
    if (function(a) * function(b) > 0){
        cout<<"Wrong Guess ! Please Guess Again."<<endl;
        return;
    }
    else{
        while (true)
        {
            c = (a + b)/2.0;
            cout << "Iteration : " <<iteration << " : " <<"Value of a : "<<a<<" and b : "<<b<<" "<<function(c)<<endl;
            if(abs(function(c)) < tolerence){
                break;
            }
            else if (function(a) * function(c) < 0){
                b = c;
            }
            else{
                a = c;
            }
            iteration ++;
        }
        cout << "Answer is : " <<c<<endl;       
    }
}   
};
int main(){
    Bisection bisection(tol) ;
    bisection.solve();
}


