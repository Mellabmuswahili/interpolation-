#include <bits/stdc++.h>
using namespace std;
 
// calculating u mentioned in the formula
float u_cal(float u, int n)
{
    float temp = u;
    for (int i = 1; i < n; i++)
        temp = temp * (u - i);
    return temp;
}
 
// calculating factorial of given number n
int fact(int n)
{
    int f = 1;
    for (int i = 2; i <= n; i++)
        f *= i;
    return f;
}
 
int main()
{
    // Number of values given
    int n = 5;
    float x[] = { 2016, 2017, 2018, 2019,2020 };
     
    // y[][] is used for difference table
    // with y[][0] used for input
    float y[n][n];
    y[0][0] = 3386.81;
    y[1][0] = 4237.25;
    y[2][0] = 3959.00;
    y[3][0] = 3853.00;
    y[4][0] = 3707.00;
 
    // Calculating the forward difference
    // table
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n - i; j++)
            y[j][i] = y[j + 1][i - 1] - y[j][i - 1];
    }
 
    // Displaying the forward difference table
    for (int i = 0; i < n; i++) {
        cout << setw(4) << x[i]
             << "\t";
        for (int j = 0; j < n - i; j++)
            cout << setw(4) << y[i][j]
                 << "\t";
        cout << endl;
    }
 
    // Value to interpolate at
    float value = 2021;
 
    // initializing u and sum
    float sum = y[0][0];
    float u = (value - x[0]) / (x[1] - x[0]);
    for (int i = 1; i < n; i++) {
        sum = sum + (u_cal(u, i) * y[0][i]) /
                                 fact(i);
    }

    cout << "Interpolated value: " <<value <<" is : " << sum << endl;

    // printing the interpolated value of 2022
    float value1 = 2022;

    // initializing u and sum
    sum = y[0][0];
    u = (value1 - x[0]) / (x[1] - x[0]);
    for (int i = 1; i < n; i++) {
        sum = sum + (u_cal(u, i) * y[0][i]) /
                                 fact(i);
    }
    cout << "Interpolated value of " << value1 << " is: " << abs(sum) << endl;

    // printing the interpolated value of 2023
    float value2 = 2023;

    // initializing u and sum
    sum = y[0][0];
    u = (value2 - x[0]) / (x[1] - x[0]);
    for (int i = 1; i < n; i++) {
        sum = sum + (u_cal(u, i) * y[0][i]) /
                                 fact(i);
    }
    cout << "Interpolated value of " << value2 << " is: " << abs(sum) << endl;
    

 
   
    return 0;
}