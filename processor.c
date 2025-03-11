#include <stdio.h>
#include "json_parser.h"
#include "processor.h"

void write_data_into_file(struct WeatherData data, const char *city) {
    FILE *weather_data_file = fopen("weather_data.txt", "w");
    if (weather_data_file == NULL) {
        printf("File opening failed!.\n");
        return;
    }
    
    fprintf(weather_data_file, "-----------------------------{Weather Report for %s}-----------------------------\n\n", city);
    fprintf(weather_data_file, " Temperature: %.2f°C\n", data.temp - 273.15); 
    fprintf(weather_data_file, " Feels like Temperature: %.2f°C\n",data.feels_like-273.15);
    fprintf(weather_data_file, " Humidity: %d%%\n", data.humidity);
    fprintf(weather_data_file, " Condition: %s\n", data.description);
    fprintf(weather_data_file, " Wind: %.2f m/s at %d°\n", data.wind_speed, data.wind_deg);

    fclose(weather_data_file);
    printf("Weather data saved to weather_data.txt\n");
    printf("\n\nIf you want to see the weather type 'cat weather_data.txt'\n\n");
    
}

