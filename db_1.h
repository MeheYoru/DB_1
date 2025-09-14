#pragma once
#include <iostream>
#include <fstream>

class Book { 
    public:
        uint32_t _id;
        std::string _title;
        std::string _author;
        std::string _end_date;
        uint32_t _score;
        Book(uint32_t id, std::string title, std::string author, std::string end_date, uint32_t score): _id(id), _title(title), _author(author), _end_date(end_date), _score(score) {};
        Book(std::string data);
        ~Book() = default;
        std::string getBook();
    private:
        uint32_t get_id();
        
};

