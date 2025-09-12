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
    std::cout << file_name << "\n";
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
    Book bk("2,Idiot,Dostoevsky,13.09.2025,10");
    bk.export_to_db(file_name);


    File.close();
    return 0;
}