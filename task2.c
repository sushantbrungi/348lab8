#include <stdio.h>

double convertToCelsius(double temp, char scale) {
    if (scale == 'C' || scale == 'c') {
        return temp;
    } else if (scale == 'F' || scale == 'f') {
        return (temp - 32) * 5 / 9;
    } else if (scale == 'K' || scale == 'k') {
        return temp - 273.15;
    } else {
        return -9999; 
    }
}

double convertFromCelsius(double tempC, char scale) {
    if (scale == 'C' || scale == 'c') {
        return tempC;
    } else if (scale == 'F' || scale == 'f') {
        return tempC * 9 / 5 + 32;
    } else if (scale == 'K' || scale == 'k') {
        return tempC + 273.15;
    } else {
        return -9999;
    }
}

void showAdvice(double tempC) {
    if (tempC < 0) {
        printf("It's freezing! Wear a heavy coat.\n");
    } else if (tempC < 10) {
        printf("It's cold. Wear a jacket.\n");
    } else if (tempC < 25) {
        printf("It's comfortable. Enjoy your day!\n");
    } else if (tempC < 35) {
        printf("It's hot. Drink water!\n");
    } else {
        printf("Extreme heat! Stay indoors.\n");
    }
}

int main() {
    double inputTemp;
    char fromScale, toScale;

    printf("Enter temperature: ");
    scanf("%lf", &inputTemp);

    printf("Enter original scale (C, F, K): ");
    scanf(" %c", &fromScale);

    printf("Convert to scale (C, F, K): ");
    scanf(" %c", &toScale);

    double tempC = convertToCelsius(inputTemp, fromScale);
    if (tempC == -9999) {
        printf("Invalid original scale.\n");
        return 1;
    }

    if (tempC < -273.15) {
        printf("Temperature is below absolute zero!\n");
        return 1;
    }

    double finalTemp = convertFromCelsius(tempC, toScale);
    if (finalTemp == -9999) {
        printf("Invalid target scale.\n");
        return 1;
    }

    printf("Converted temperature: %.2f %c\n", finalTemp, toScale);
    showAdvice(tempC);

    return 0;
}
