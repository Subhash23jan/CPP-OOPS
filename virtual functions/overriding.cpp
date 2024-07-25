// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
void sum(string s){
    cout<<s<<endl;
}
void sum(int s){
    cout<<s<<" "<<s<<endl;
}
int sum(int a,int b)
{
    return a+b;
}
int sum(int a,int b,int c=10)
{
    return a+b;
}
double sum(double a,double b)
{
    return a*b;
}
int main() {
    // Write C++ code here
    cout << "Try programiz.pro"<<endl;
    int a=10,b=5;
    cout<<sum(10.3,5.2);
    return 0;
}