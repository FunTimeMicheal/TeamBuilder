#ifndef DATABASE_H
#define DATABASE_H

#include <string>
#include "sqlite3.h"

int open_db();

void create_table();

void add_deelnemer(const std::string& person, const std::string& volwassen, const std::string& internet);

void close_db();

#endif 
