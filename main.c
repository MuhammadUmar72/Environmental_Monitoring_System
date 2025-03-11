#include <stdio.h> 
#include <stdlib.h>
#include "api_handler.h"
#include "json_parser.h"
#include "processor.h"

int main() {
    char city[]="Karachi";   
    const char *apiKey = "ac2bc8a89a7d3bc1045742a7d7969fe5";

    char *response = fetch_weather_data(city, apiKey);
    if (response == NULL) {
        printf("Weather data fetching failed!.\n");
        return 1;
    }

    struct WeatherData data = parse(response);
    free(response); 

    if (data.valid) {
        write_data_into_file(data, city);
        free(data.description); 
    } else {
        printf("Error: Failed to parse weather data.\n");
    }
    return 0;
}

