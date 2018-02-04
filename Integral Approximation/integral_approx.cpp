/** Program to approximate the value of input polynomial function
 * Mathias Novianto
 * 4 February 2018
 * */
#include <iostream>
#include <math.h>
#include <vector>
#include <string>
using namespace std;
class Polinom{
    //A single polinom
    public:
        //constructor
        Polinom(float _coeff, float _degree){
            coeff = _coeff;
            degree = _degree;
        }
        //evaluate a single value of x
        double countFx(double x){
            return (coeff*pow(x,degree));
        }
        float getCoeff(){
            return coeff;
        }
        float getDegree(){
            return degree;
        }
        float setCoeff(float _coeff){
            coeff = _coeff;
        }
        float setDegree(float _degree){
            degree = _degree;
        }
    private:
        float coeff;
        float degree;
};

class ArrPolinom{
    public:
        //Input the equation from the user
        void fillFromUser(int n){
            double coeff,degree;
           for(int i=0 ;i<n;i++){
               cout<<"Coefficient "<<i+1<<" = ";
               cin >> coeff;
               cout<<"Degree "<<i+1<<" = ";
               cin>>degree;
               addPolinom(Polinom(coeff,degree));
           }
        }
        //print the equation to user
        //example :
        void printPolinom(){
            int i;
            for(i=0;i<vp.size();i++){
                if(vp[i].getCoeff()>0){
                    cout<<'+';
                }
                cout<<vp[i].getCoeff()<<"x^"<<vp[i].getDegree();
            }
        }
        void addPolinom(Polinom P){
            vp.push_back(P);
        }
        //evaluate the value of a single x in all array polynom element
        double countFx(double x){
            double tempFx = 0.0;
            for(int j=0; j < vp.size();j++){
                tempFx += vp[j].countFx(x);
            }
            return tempFx;
        }
        //Count the value of integral
        double count(float low, float high, int n){
            double tempIntegral = 0.0;
            double dx = (high-low)/(float)n;
            double i = low;
            while(i+dx < high){
                tempIntegral += (countFx(i)+countFx(i+dx))*dx/2.0;
                i += dx;
                //cout<<"i = "<<i<<" and its value "<<tempIntegral<<endl;
            }
            //For the last part of trapezoid
            tempIntegral += (countFx(i)+countFx(high))*(high-i)/2.0;
            return tempIntegral;
        }
    private:
        vector<Polinom> vp;
};



int main(){
    cout<<"Input the number of polynom you want ";
    int n;
    cin >> n;
    ArrPolinom arrP;
    arrP.fillFromUser(n);
    cout<<"Enter the lower bound ";
    double low, high; // the interval of the integral
    cin>>low;
    cout<<"Enter the high bound ";
    cin>>high;
    //the user must input how precise they want their calculation will be
    //higher calculation means more resource
    cout<<"How precise do you want ? (low, medium, high) ";
    string precision;
    cin>>precision;
    if(precision=="low"){
        cout<<arrP.count(low, high,10);
    }
    else if(precision=="medium"){
        cout<<arrP.count(low,high,100);
    }
    else{
        cout<<arrP.count(low,high,10000);
    }
    //arrP.printPolinom();
}