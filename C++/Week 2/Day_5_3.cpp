#include <iostream>
#include <cmath>
using namespace std;

class SimpleCalculator
{
protected:
    double num1, num2;

public:
    void getSimpleInput()
    {
        cout << "Enter two numbers for simple calculator: ";
        cin >> num1 >> num2;
    }

    void performSimpleOperations()
    {
        cout << "Addition: " << num1 + num2 << endl;
        cout << "Subtraction: " << num1 - num2 << endl;
        cout << "Multiplication: " << num1 * num2 << endl;
        if (num2 != 0)
        {
            cout << "Division: " << num1 / num2 << endl;
        }
        else
        {
            cout << "Division: Division by zero error!" << endl;
        }
    }
};

class ScientificCalculator
{
protected:
    double num1, num2;

public:
    void getScientificInput()
    {
        cout << "Enter two numbers for scientific calculator: ";
        cin >> num1 >> num2;
    }

    void performScientificOperations()
    {
        cout << "Power: " << pow(num1, num2) << endl;
        if (num1 >= 0)
        {
            cout << "Square root of num1: " << sqrt(num1) << endl;
        }
        else
        {
            cout << "Square root of num1: Complex number error!" << endl;
        }
        if (num2 > 0)
        {
            cout << "Logarithm of num2: " << log(num2) << endl;
        }
        else
        {
            cout << "Logarithm of num2: Logarithm error!" << endl;
        }
        cout << "Sine of num1: " << sin(num1) << endl;
    }
};

class HybridCalculator : public SimpleCalculator, public ScientificCalculator
{
public:
    void displayResults()
    {
        getSimpleInput();
        performSimpleOperations();
        getScientificInput();
        performScientificOperations();
    }
};

int main()
{
    HybridCalculator calc;
    calc.displayResults();
    return 0;
}
