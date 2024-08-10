#include <iostream>

using namespace std;

double celsiusToFahrenheit(double celsius) {
    return (celsius * 9.0 / 5.0) + 32;
}

double celsiusToKelvin(double celsius) {
    return celsius + 273.15;
}

double fahrenheitToCelsius(double fahrenheit) {
    return (fahrenheit - 32) * 5.0 / 9.0;
}

double fahrenheitToKelvin(double fahrenheit) {
    return (fahrenheit - 32) * 5.0 / 9.0 + 273.15;
}

double kelvinToCelsius(double kelvin) {
    return kelvin - 273.15;
}

double kelvinToFahrenheit(double kelvin) {
    return (kelvin - 273.15) * 9.0 / 5.0 + 32;
}

int main() {
    double temperature;
    char unit;

    cout << "Temperature Converter" << endl;
    cout << "Enter the temperature value: ";
    cin >> temperature;
    cout << "Enter the unit of measurement (C for Celsius, F for Fahrenheit, K for Kelvin): ";
    cin >> unit;

    switch (unit) {
        case 'C':
        case 'c':
            cout << temperature << "°C is equal to " << celsiusToFahrenheit(temperature) 
                 << "°F and " << celsiusToKelvin(temperature) << "K." << endl;
            break;
        case 'F':
        case 'f':
            cout << temperature << "°F is equal to " << fahrenheitToCelsius(temperature) 
                 << "°C and " << fahrenheitToKelvin(temperature) << "K." << endl;
            break;
        case 'K':
        case 'k':
            cout << temperature << "K is equal to " << kelvinToCelsius(temperature) 
                 << "°C and " << kelvinToFahrenheit(temperature) << "°F." << endl;
            break;
        default:
            cout << "Invalid unit!" << endl;
    }

    return 0;
}