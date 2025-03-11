#!/bin/bash

DIR="./files"

mkdir -p "$DIR"

file_count=$(ls "$DIR" | wc -l)

if [ "$file_count" -ge 7 ]; then
    oldest_file=$(ls -t "$DIR" | tail -n 1)  
    rm "$DIR/$oldest_file"                  
fi

timestamp=$(date +"%Y%m%d_%H%M%S")
output_file="$DIR/output_$timestamp.txt"

if [ -f "weather_data.txt" ]; then
    cat weather_data.txt >> "$output_file"
else
    echo "Weather data file 'weather_data.txt' not found." >&2 
fi

echo "Data saved in $output_file"

