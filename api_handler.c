#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include "api_handler.h"

struct Memory {
    char *data;
    size_t size;
};

static size_t writeCallback(void *contents, size_t size, size_t nmemb, void *userp) {
    size_t totalSize = size * nmemb;
    struct Memory *mem = (struct Memory *)userp;

    char *newData = realloc(mem->data, mem->size + totalSize + 1);
    if (newData == NULL) {
        printf("Memory allocation failed!.\n");
        return 0;
    }

    mem->data = newData;
    memcpy(&(mem->data[mem->size]), contents, totalSize);
    mem->size += totalSize;
    mem->data[mem->size] = '\0'; 

    return totalSize;
}

char *fetch_weather_data(const char *city, const char *apiKey) {
    CURL *curl;
    CURLcode res;

    struct Memory chunk = {NULL, 0};
    curl = curl_easy_init();
    if (curl == NULL) {
        printf("CURL initialization failed\n");
        return NULL;
    }

    char url[256];
    snprintf(url, sizeof(url), "https://api.openweathermap.org/data/2.5/weather?q=%s&appid=%s", city, apiKey);

    curl_easy_setopt(curl, CURLOPT_URL, url);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)&chunk);

    res = curl_easy_perform(curl);
    if (res != CURLE_OK) {
        printf("Error: %s\n", curl_easy_strerror(res));
        free(chunk.data);
        chunk.data = NULL;
    }
    FILE *raw_data_file = fopen("raw_data.json", "w");
    fwrite(chunk.data, 1, chunk.size, raw_data_file);
    fclose(raw_data_file);

    curl_easy_cleanup(curl);
    return chunk.data;
}

