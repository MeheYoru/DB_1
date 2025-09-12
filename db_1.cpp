#include "db_1.h"
#include <cstring>
#include <sstream>

void Book::export_to_db(FILE* File) {
    fprintf(File, "%d, %s, %s, %s, %d\n", _id, _title, _author, _end_date, _score);
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