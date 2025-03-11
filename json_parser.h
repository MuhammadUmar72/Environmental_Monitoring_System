#ifndef JSON_PARSER_H
#define JSON_PARSER_H

struct WeatherData {
    double temp;
    char *description;
    double feels_like; 
    int humidity; 
    double wind_speed;
    int wind_deg;
    int valid;
};

struct WeatherData parse(const char *raw_data);

#endif

