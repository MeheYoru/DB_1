#include "db_1.h"
#include <cstring>
#include <sstream>


// void Book::export_to_db(std::string file_name) {
//     std::fstream File(file_name, std::ios_base::app);
//     File << _id << "," << _title << "," << _author << "," << _end_date << "," << _score << "\n";
//     File.close();
// }


std::string Book::getBook() {
    std::string result;
    result = "title: " + _title + " Author: " + _author + " Finished on: " + _end_date + " Score: " + std::to_string(_score) + "\n";
    return result;
}

uint32_t Book::get_id() {
    return this->_id;
}
Book::Book(std::string data) {
    std::stringstream ss(data);
        std::string item;
        std::getline(ss, item, ',');
        _id = stoi(item);
        std::getline(ss, item, ',');
        _title = item;
        std::getline(ss, item, ',');
        _author = item;
        std::getline(ss, item, ',');
        _end_date = item;
        std::getline(ss, item, ',');
        _score = stoi(item);     
}
// Id, Title, Author, Date, Score
// "%d, %s, %s, %s, %d"