/*

Write a program that takes in three arguments, a start temperature (in Celsius), 
an end temperature (in Celsius) and a step size.

Print out a table that goes from the start temperature to the end temperature, 
in steps of the step size; for each value you also need to provide the Fahrenheit value; 
you do not actually need to print the final end temperature if the step size does not exactly match.

You should perform input validation: do not accept start temperatures less than a lower limit 
(which your code should specify as a constant) or higher than an upper limit (which your code 
should also specify).

You should not allow a step size greater than the difference in temperatures.

*/

#include <iostream>
#include <stdio.h>

using namespace std;

#define lowerLimitTemperature 10
#define higherLimitTemperature 50000
#define CELSIUS_TO_FAHRENHEIT(c) ((c) * 1.8 + 32)


int main()
{
    float initialTemperature;
    float finalTemperature;
    float stepSize;

    do
    {
        cout << "Insert the initial temperature: ";
        cin >> initialTemperature;
        if(initialTemperature < lowerLimitTemperature)
        {
            cout << "\nIncorrect - the lower limit is: " << lowerLimitTemperature << endl << endl;
        }
        else if(initialTemperature > higherLimitTemperature)
        {
            cout << "\nIncorrect - the higher limit is: " << higherLimitTemperature << endl << endl;
        }
    } while ((initialTemperature < lowerLimitTemperature) || (initialTemperature > higherLimitTemperature));
    

    do
    {
        cout << "Insert the final temperature: ";
        cin >> finalTemperature;
        if(finalTemperature <= initialTemperature)
        {
            cout << "\nIncorrect - the final temperature must be higher than the initial temperature (" << initialTemperature << ")" << endl << endl;
        }
        else if(finalTemperature > higherLimitTemperature)
        {
            cout << "\nIncorrect - the higher limit is: " << higherLimitTemperature << endl << endl;
        }
    } while ((finalTemperature <= initialTemperature) || (finalTemperature > higherLimitTemperature));
    
    
    do
    {
        cout << "Insert the step size: ";
        cin >> stepSize;
        if(stepSize <= 0)
        {
            cout << "\nIncorrect - the step size must be a positive number" << endl << endl;
        }
        else if(stepSize > (finalTemperature - initialTemperature))
        {
            cout << "\nIncorrect - the step size is too big (it is larger than the difference between final and initial temperature)" << endl << endl;
        }
    } while ((stepSize <= 0) || (stepSize > (finalTemperature - initialTemperature)));
    

    cout << "Celsius\t\tFahrenheit" << endl;
    cout << "-------\t\t----------" << endl;

    float initialTemperatureTemporary = initialTemperature;

    do
    {
        printf("%.6f\t%.6f\n", initialTemperatureTemporary, CELSIUS_TO_FAHRENHEIT(initialTemperatureTemporary));
        initialTemperatureTemporary += stepSize;
    } while (initialTemperatureTemporary <= finalTemperature);
    
  
    return 0;
}
