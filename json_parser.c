#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <json-c/json.h>
#include "json_parser.h"

struct WeatherData parse(const char *raw_data) {
    struct WeatherData data = {0}; 

    struct json_object *parsed_json = json_tokener_parse(raw_data);
    if (parsed_json == NULL) {
        printf("JSON Parsing Failed!.\n");
        return data;
    }

    struct json_object *main_obj, *weather_array, *weather_obj,*wind_obj, *temp, *description, *humidity, *feels_like, *wind_speed, *wind_deg;
    
    json_object_object_get_ex(parsed_json, "main", &main_obj);
    json_object_object_get_ex(main_obj, "temp", &temp);
    data.temp = json_object_get_double(temp);
    
    json_object_object_get_ex(main_obj, "feels_like", &feels_like);
    data.feels_like = json_object_get_double(feels_like);
    
    json_object_object_get_ex(main_obj, "humidity", &humidity);
    data.humidity = json_object_get_double(humidity);
    
    json_object_object_get_ex(parsed_json, "weather", &weather_array);
    weather_obj = json_object_array_get_idx(weather_array, 0);
    json_object_object_get_ex(weather_obj, "description", &description);
    data.description = strdup(json_object_get_string(description));
    
    json_object_object_get_ex(parsed_json, "wind", &wind_obj);
    data.wind_speed=json_object_object_get_ex(wind_obj, "speed", &wind_speed);
    data.wind_deg=json_object_object_get_ex(wind_obj, "deg", &wind_deg);

    if (data.temp > 0 && data.description != NULL) {
        data.valid = 1; 
    }
    
    if (data.temp > 15.0) {
        system("notify-send 'Weather Alert' 'Temperature exceed to 15°C'");
    }


    json_object_put(parsed_json);
    return data;
}

