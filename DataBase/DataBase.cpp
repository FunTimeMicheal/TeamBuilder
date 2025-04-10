#include "DataBase.h"
#include <iostream>
#include "sqlite3.h"

sqlite3* db;

int open_db() {
    int rc = sqlite3_open("namen.db", &db);
    if (rc) {
        std::cerr << "Kan de database niet openen: " << sqlite3_errmsg(db) << "\n";
        return rc;
    }
    std::cout << "Database geopend.\n";
    return rc;
}

void create_table() {
    const char* createTableSQL = R"(
        CREATE TABLE IF NOT EXISTS deelnemers (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            naam TEXT NOT NULL,
            volwassen TEXT NOT NULL,
            internet TEXT NOT NULL
        );
    )";
    
    int rc = sqlite3_exec(db, createTableSQL, 0, 0, 0);
    if (rc != SQLITE_OK) {
        std::cerr << "Kan de tabel niet aanmaken: " << sqlite3_errmsg(db) << "\n";
    } else {
        std::cout << "Tabel 'deelnemers' is aangemaakt of bestaat al.\n";
    }
}

void add_deelnemer(const std::string& person, const std::string& volwassen, const std::string& internet) {
    const char* insertSQL = "INSERT INTO deelnemers (naam, volwassen, internet) VALUES (?, ?, ?);";
    sqlite3_stmt* stmt;
    int rc = sqlite3_prepare_v2(db, insertSQL, -1, &stmt, 0);
    
    if (rc != SQLITE_OK) {
        std::cerr << "Kan de INSERT-query niet voorbereiden: " << sqlite3_errmsg(db) << "\n";
        return;
    }
    
    sqlite3_bind_text(stmt, 1, person.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, volwassen.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 3, internet.c_str(), -1, SQLITE_STATIC);

    rc = sqlite3_step(stmt);
    if (rc != SQLITE_DONE) {
        std::cerr << "Fout bij uitvoeren van de query: " << sqlite3_errmsg(db) << "\n";
    } else {
        std::cout << "Deelnemer toegevoegd: " << person << "\n";
    }

    sqlite3_finalize(stmt);
}

void close_db() {
    sqlite3_close(db);
    std::cout << "Database gesloten.\n";
}
