#include<iostream>

using namespace std;

double func(double x)
{
    return x*x*x - 2*x - 5;
}

void bisection(double a, double b)
{
    if (func(a) * func(b) >= 0)
    {
        cout << "You have not assumed right a and b\n";
        return;
    }

    int count = 0;

    double c;
    while ((b-a) > 0.001)
    {
        c = (a+b)/2;
        if (func(c) == 0.0)
            break;

        else if (func(c)*func(a) < 0)
            b = c;
        else
            a = c;
        count++;
        cout << count <<". The value of root is : " << c <<endl;
    }

    cout<<endl<<"The root of the given equation x^3-2x-5 = 0 correct to 3 decimal places is "<<c;
}

int main()
{
    cout<<"Syed Ali Hasan"<<endl<<"IT, 4th Semester"<<endl<<"02220803117"<<endl;
    cout<<endl;
    bisection(2,3);
}