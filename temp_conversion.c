#include <stdio.h>

// Function declarations
float celsius_to_fahrenheit(float celsius);
float fahrenheit_to_celsius(float fahrenheit);
float celsius_to_kelvin(float celsius);
float kelvin_to_celsius(float kelvin);
float fahrenheit_to_kelvin(float fahrenheit);
float kelvin_to_fahrenheit(float kelvin);
void categorize_temperature(float celsius);

int main() {
    float temperature, converted_temp;
    int input_scale, target_scale;

    printf("Temperature Conversion Utility\n");
    printf("==================================\n");

    while (1) {
        printf("Enter the temperature (negative value to exit): ");
        if (scanf("%f", &temperature) != 1 || temperature < -273.15) {
            printf("Exiting...\n");
            break;
        }

        printf("Choose the current scale (1) Celsius, (2) Fahrenheit, (3) Kelvin: ");
        scanf("%d", &input_scale);
        if (input_scale < 1 || input_scale > 3) {
            printf("Invalid scale! Please enter a valid scale (1-3).\n");
            continue;
        }

        printf("Convert to (1) Celsius, (2) Fahrenheit, (3) Kelvin: ");
        scanf("%d", &target_scale);
        if (target_scale < 1 || target_scale > 3 || target_scale == input_scale) {
            printf("Invalid target scale or same as input! Please choose a different valid scale.\n");
            continue;
        }

        // Perform conversion based on input and target scales
        switch (input_scale) {
            case 1: // Celsius
                if (target_scale == 2)
                    converted_temp = celsius_to_fahrenheit(temperature);
                else
                    converted_temp = celsius_to_kelvin(temperature);
                break;

            case 2: // Fahrenheit
                if (target_scale == 1)
                    converted_temp = fahrenheit_to_celsius(temperature);
                else
                    converted_temp = fahrenheit_to_kelvin(temperature);
                break;

            case 3: // Kelvin
                if (target_scale == 1)
                    converted_temp = kelvin_to_celsius(temperature);
                else
                    converted_temp = kelvin_to_fahrenheit(temperature);
                break;
        }

        // Display the converted temperature
        if (target_scale == 1)
            printf("Converted temperature: %.2f°C\n", converted_temp);
        else if (target_scale == 2)
            printf("Converted temperature: %.2f°F\n", converted_temp);
        else
            printf("Converted temperature: %.2fK\n", converted_temp);

        // Categorize and provide advisory based on Celsius
        float converted_celsius;
        if (target_scale == 1) {
            converted_celsius = converted_temp;
        } else if (target_scale == 2) {
            converted_celsius = fahrenheit_to_celsius(converted_temp);
        } else {
            converted_celsius = kelvin_to_celsius(converted_temp);
        }

        categorize_temperature(converted_celsius);
    }

    return 0;
}

// Function definitions
float celsius_to_fahrenheit(float celsius) {
    return (celsius * 9.0 / 5.0) + 32;
}

float fahrenheit_to_celsius(float fahrenheit) {
    return (fahrenheit - 32) * 5.0 / 9.0;
}

float celsius_to_kelvin(float celsius) {
    return celsius + 273.15;
}

float kelvin_to_celsius(float kelvin) {
    return kelvin - 273.15;
}

float fahrenheit_to_kelvin(float fahrenheit) {
    return celsius_to_kelvin(fahrenheit_to_celsius(fahrenheit));
}

float kelvin_to_fahrenheit(float kelvin) {
    return celsius_to_fahrenheit(kelvin_to_celsius(kelvin));
}

void categorize_temperature(float celsius) {
    if (celsius < 0) {
        printf("Temperature category: Freezing\n");
        printf("Weather advisory: Be careful, it's freezing. Stay warm!\n");
    } else if (celsius >= 0 && celsius < 10) {
        printf("Temperature category: Cold\n");
        printf("Weather advisory: Wear a jacket.\n");
    } else if (celsius >= 10 && celsius < 25) {
        printf("Temperature category: Comfortable\n");
        printf("Weather advisory: You should feel comfortable.\n");
    } else if (celsius >= 25 && celsius < 35) {
        printf("Temperature category: Hot\n");
        printf("Weather advisory: It's hot. Stay hydrated!\n");
    } else {
        printf("Temperature category: Extreme Heat\n");
        printf("Weather advisory: Stay indoors and avoid extreme heat.\n");
    }
}
