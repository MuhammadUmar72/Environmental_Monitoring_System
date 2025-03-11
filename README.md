# Environmental_Monitoring_System
This repository hosts an Integrated Environmental Monitoring System developed in C. It retrieves and processes real-time environmental data from a free API, demonstrating efficient data handling, modular design, and task automation.

Features:

* Real-Time Data Retrieval: Fetch environmental data (e.g., temperature, humidity) from a free API.

* Data Storage: Save raw and processed data in structured files.

* Task Automation: Use shell scripts for periodic data retrieval and processing.

* Optimized Performance: Implement pointers and dynamic memory allocation for efficient data handling.

* Real-Time Alerts: Notify personnel of critical readings using Linux system calls.

* Modular Design: Organized with header files for better readability and maintenance.

Requirements:

* GCC Compiler

* Linux OS or a compatible environment

* Shell scripting enabled

* Access to a free API for environmental data (e.g., OpenWeatherMap)

Installation and Setup:

Clone the repository:
git clone https://github.com/Ahad-Khan-02/Environmental_Monitoring_System.git

Compile the program:
gcc main.c api_handler.c json_parser.c processor.c -o EMS -lcurl -ljson-c

Run the program:
./EMS

Automate tasks using shell scripts:
0 * * * /path/to/your/shell_scripting.sh

Repository Structure

Source_Files : main.c , api_handler.c , json_parser.c , processor.c

Header_Files : api_handler.h , json_parser.h , processor.h

text_File (for processed data) : weather_data.txt

json_File (for raw data) : raw_data.json
