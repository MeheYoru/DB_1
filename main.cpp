#include <iostream>
#include <fstream>
#include <stdexcept>
#include <utility>
#include <vector>
#include <sstream>
#include <string>
#include "db_1.h"

void save_to_file(std::vector<std::pair<uint32_t, Book>>& db, std::string file_name) {
    std::fstream File(file_name, std::ios::out | std::ios::trunc);
    for(auto it: db) {
        File << it.second._id << "," << it.second._title << "," << it.second._author << "," << it.second._end_date << "," << it.second._score << "\n";
    }
}

void REM(std::vector<std::pair<uint32_t, Book>>& db, auto it) {
    
}




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
    File.close();
    while(true) {
        printf("0. Close    1. Get      2. Edit     3. Remove   4. Add\n");
        printf("Enter command:  \n");
        std::string command_temp;
        uint8_t command;
        std::cin >> command_temp;
        command = stoi(command_temp);
        if(command == 0) break;
        switch (command)
        {
        case 1:
        {
            printf("Enter ID:\n");
            std::string id_temp;
            std::cin >> id_temp;
            uint8_t id_search;
            id_search = stoi(id_temp);
            for(auto it: db) {
                if(it.first == id_search) {
                    std::cout << "Book found, ";
                    std::cout << it.second.getBook();
                }
            }
            save_to_file(db, file_name);
            break;
        }
        case 2:
        {
            printf("Enter ID:\n");
            bool flag = false;
            std::string id_temp;
            std::cin >> id_temp;
            uint8_t id_search;
            id_search = stoi(id_temp);
            for(auto it: db) {
                if(it.first == id_search) {
                    std::string title, author, date, score;
                    printf("Title:\n");
                    std::cin >> title;
                    printf("Author:\n");
                    std::cin >> author;
                    printf("Date:\n");
                    std::cin >> date;
                    printf("Score:\n");
                    std::cin >> score;
                    db.push_back(std::make_pair(id_search, Book(id_search, title, author, date, stoi(score))));
                    save_to_file(db, file_name);
                    std::cout << it.second.getBook();
                    flag = true;
                }
            }
            if(flag) std::cout << "ID is already used";
            save_to_file(db, file_name);
            break;
        }
        case 3:
            {
            printf("Enter ID:\n");
            std::string id_temp;
            std::cin >> id_temp;
            uint8_t id_search;
            id_search = stoi(id_temp);
            for(uint16_t i = 0; i < db.size(); i++) {
                if(db[i].first == id_search) {
                    db.erase(db.begin()+i);
                    std::cout << "Book deleted ";
                }
            }
            save_to_file(db, file_name);
            break;
        }
        case 4:
        {
            printf("Enter ID:\n");
            bool flag = false;
            std::string id_temp;
            std::cin >> id_temp;
            uint8_t id_search;
            id_search = stoi(id_temp);
            for(auto it: db) {
                if(it.first == id_search) {
                    std::cout << "ID is already used";
                    std::cout << it.second.getBook();
                    flag = true;
                }
            }
            if(flag) break;
            std::string title, author, date, score;
            printf("Title:\n");
            std::cin >> title;
            printf("Author:\n");
            std::cin >> author;
            printf("Date:\n");
            std::cin >> date;
            printf("Score:\n");
            std::cin >> score;
            db.push_back(std::make_pair(id_search, Book(id_search, title, author, date, stoi(score))));
            save_to_file(db, file_name);
            break;
        }
        default:
            break;
        }
        continue;
    }
    return 0;
}