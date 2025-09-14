#include <iostream>
#include <fstream>
#include <stdexcept>
#include <utility>
#include <vector>
#include <sstream>
#include <string>
#include "db_1.h"

int main() {
    printf("Select option: \n1. Create new file \n2. Open file\n");
    uint8_t answer = 0;
    scanf("%d", &answer);
    std::string file_name = ""; 

    // Opening/creating file
    if(answer == 2) {
        file_name = "new_file.txt";
        printf("Enter file name: ");
        std::cin >> file_name;
        std::fstream File(file_name);
        if(!File) throw std::invalid_argument("File not found");
    } else {
        std::fstream File("New_file.txt");
        if(!File) std::ofstream File("New_file.txt");
        else {
            File.close();
            uint16_t i = 1;
            while(true) {
                char temp_name[100];
                sprintf(temp_name, "New_file (%d).txt", i);
                std::fstream File_temp(temp_name);
                if(File_temp) {
                    File_temp.close();
                    i++;
                    continue;
                } else {
                    std::ofstream File(temp_name);
                    File.close();
                    file_name = temp_name;
                    break;
                }
            }
        }
    }

    std::fstream File(file_name);
    std::vector<std::pair<uint32_t, Book>> db;
    std::string s;
    while(getline(File, s)) {
        std::stringstream ss(s);
        std::string item;
        std::getline(ss, item, ',');
        uint32_t temp = stoi(item);
        db.push_back(std::make_pair(temp, Book(s)));
    }

    while(true) {
        printf("0. Close    1. Get      2. Edit     3. Remove \n");
        printf("Enter command:  \n");
        uint8_t command;
        std::cin >> command;
        if(command == 0) break;
        switch (command)
        {
        case 1:
            std::cout << "GET\n";
            break;
        case 2:
            std::cout << "EDIT\n";
            break;
        case 3:
            std::cout << "REM\n";
            break;
        default:
            break;
        }
        continue;
    }


    for(auto it: db) {
        File << it.second._id << "," << it.second._title << "," << it.second._author << "," << it.second._end_date << "," << it.second._score << "\n";
    }

    File.close();
    return 0;
}