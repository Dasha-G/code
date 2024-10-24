#include <iostream>
#include <fstream>
#include <cmath>
#include <stdio.h>

using namespace std;

double calculate_y(double x, int n) {
    double y;
    if (x < 7) {
        double product = 1.0;
        for (int i = 3; i <= n - 4; i++) {
            product *= x / (5 + i);
        }
        y = product;
    }
    else {
        double sum = 0.0;
        for (int j = 0; j <= n; j++) {
            double product = 1.0;
            for (int i = 1; i <= n + 1; i++) {
                product *= (1.0 / (2 * x) + (3 * i) / (i - j + 1));
            }
            sum += product;
        }
        y = sum;
    }
    return y;
}


int main() {
    double a, b, step;
    int n, num;
    
    while (true) {
        start:
        cout << "Start (enter 0 to stop or ineger to start): ";
        cin >> num;

        if (num == 0) {
            break;
        };

        cout << "Enter the range start (a): ";
        while (!(cin >> a)) {
            cout << "Invalid input. Please enter a number: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        sstart:
        cout << "Enter the range end (b): ";
        while (!(cin >> b)) {
            cout << "Invalid input. Please enter a number: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        if (a > b) {
            cout << "Error. a must be more than b" << endl;
            goto sstart;
        }

        cout << "Enter the step value: ";
        while (!(cin >> step)) {
            cout << "Invalid input. Please enter a number: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        cout << "Enter the value of n: ";
        while (!(cin >> n) || n != floor(n)) {  
            cout << "Error: n must be an integer. Please enter a valid integer: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        
        

        ofstream out("resultforequation.txt", ios::app);
        if (out.is_open()) {
            if (n <= 7) {
                cout << "Error. n value is less or equal than 7 " << endl;
                out << "Error: n value is less or equal than 7 " << endl;
                goto start;
            }
            if (step <= 0) {
                cout << "Error: step must be more than 0" << endl;
                out << "Error: step must be more than 0" << endl;
                goto start;
            }
            if(n>7) {
                int max_iterations = 1000;
                int iteration_count = 0;
                for (double x = a; x <= b; x += step) {
                    iteration_count++;

                    if (iteration_count > max_iterations) {
                        cout << "Error: Maximum iteration count exceeded." << endl;
                        out << "Error: Maximum iteration count exceeded." << endl;
                        goto start;
                    }

                    double y = calculate_y(x, n);
                    cout << "For x = " << x << ", y = " << y << endl;
                    out << "For x = " << x << ", y = " << y << endl;
                    
                };

                cout << "Finished processing. Do you want to continue?" << endl;
                goto start;
            }     
        } 
        out.close();        
    }      
    return 0;
}


