#include <stdio.h>

double toCelsius(double value, char scale) {
    if (scale == 'C' || scale == 'c') return value;
    if (scale == 'F' || scale == 'f') return (value - 32) * 5.0 / 9.0;
    if (scale == 'K' || scale == 'k') return value - 273.15;
    return -9999; // 
}

double fromCelsius(double celsius, char scale) {
    if (scale == 'C' || scale == 'c') return celsius;
    if (scale == 'F' || scale == 'f') return celsius * 9.0 / 5.0 + 32;
    if (scale == 'K' || scale == 'k') return celsius + 273.15;
    return -9999; 
}

void printCategory(double celsius) {
    if (celsius < 0) {
        printf("Temperature category: Freezing\nWeather advisory: Wear a heavy coat.\n");
    } else if (celsius < 10) {
        printf("Temperature category: Cold\nWeather advisory: Wear a jacket.\n");
    } else if (celsius < 25) {
        printf("Temperature category: Comfortable\nWeather advisory: Enjoy your day!\n");
    } else if (celsius < 35) {
        printf("Temperature category: Hot\nWeather advisory: Drink lots of water!\n");
    } else {
        printf("Temperature category: Extreme Heat\nWeather advisory: Stay indoors!\n");
    }
}

int main(void) {
    double value;
    char from, to;

    printf("Enter the temperature value: ");
    if (scanf("%lf", &value) != 1) {
        printf("Invalid temperature input.\n");
        return 1;
    }

    printf("Enter the original scale (C, F, or K): ");
    scanf(" %c", &from);

    printf("Enter the scale to convert to (C, F, or K): ");
    scanf(" %c", &to);

    double celsius = toCelsius(value, from);
    if (celsius == -9999) {
        printf("Invalid input scale.\n");
        return 1;
    }

    if (celsius < -273.15) {
        printf("Invalid temperature below absolute zero.\n");
        return 1;
    }

    double result = fromCelsius(celsius, to);
    if (result == -9999) {
        printf("Invalid target scale.\n");
        return 1;
    }

    printf("Converted temperature: %.2f %c\n", result, to);
    printCategory(celsius);

    return 0;
}
