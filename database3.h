#include <iostream>
#include <vector>
#include <string>
#include <cstdlib> // для rand()
#include <ctime>   // для time()
#include "sqlite3.h"
#include <exception>
class KeyValueStore {
public:
    KeyValueStore(const std::string& dbName) {
        if (sqlite3_open(dbName.c_str(), &db) != SQLITE_OK) {
            std::cerr << "Не удалось открыть базу данных: " << sqlite3_errmsg(db) << std::endl;
            exit(1);
        }
        
        const char* sqlCreateTable = "CREATE TABLE IF NOT EXISTS kv_store (key TEXT PRIMARY KEY, value TEXT);";
        executeSQL(sqlCreateTable);
    }

    ~KeyValueStore() {
        sqlite3_close(db);
    }

    void add(const std::string& key, const std::string& value) {
        std::string sqlInsert = "INSERT OR REPLACE INTO kv_store (key, value) VALUES (?, ?);";
        sqlite3_stmt* stmt;
        
        if (sqlite3_prepare_v2(db, sqlInsert.c_str(), -1, &stmt, nullptr) != SQLITE_OK) {
            std::cerr << "Ошибка подготовки SQL запроса: " << sqlite3_errmsg(db) << std::endl;
            return;
        }
        
        sqlite3_bind_text(stmt, 1, key.c_str(), -1, SQLITE_STATIC);
        sqlite3_bind_text(stmt, 2, value.c_str(), -1, SQLITE_STATIC);
        
        if (sqlite3_step(stmt) != SQLITE_DONE) {
            std::cerr << "Ошибка выполнения SQL запроса: " << sqlite3_errmsg(db) << std::endl;
        }
        
        sqlite3_finalize(stmt);
    }

    void remove(const std::string& key) {
        std::string sqlDelete = "DELETE FROM kv_store WHERE key = ?;";
        sqlite3_stmt* stmt;

        if (sqlite3_prepare_v2(db, sqlDelete.c_str(), -1, &stmt, nullptr) != SQLITE_OK) {
            std::cerr << "Ошибка подготовки SQL запроса: " << sqlite3_errmsg(db) << std::endl;
            return;
        }

        sqlite3_bind_text(stmt, 1, key.c_str(), -1, SQLITE_STATIC);

        if (sqlite3_step(stmt) != SQLITE_DONE) {
            std::cerr << "Ошибка выполнения SQL запроса: " << sqlite3_errmsg(db) << std::endl;
        }

        sqlite3_finalize(stmt);
    }

    
    std::string get(const std::string& key) {
        std::string sqlSelect = "SELECT value FROM kv_store WHERE key = ?;";
        sqlite3_stmt* stmt;

        if (sqlite3_prepare_v2(db, sqlSelect.c_str(), -1, &stmt, nullptr) != SQLITE_OK) {
            std::cerr << "Ошибка подготовки SQL запроса: " << sqlite3_errmsg(db) << std::endl;
            return ""; // Возвращаем пустую строку в случае ошибки
        }

        sqlite3_bind_text(stmt, 1, key.c_str(), -1, SQLITE_STATIC);

        if (sqlite3_step(stmt) == SQLITE_ROW) {
            const unsigned char* text = sqlite3_column_text(stmt, 0);
            std::string value = reinterpret_cast<const char*>(text);
            sqlite3_finalize(stmt);
            return value; // Возвращаем найденное значение
        } else {
            std::cerr << "Предупреждение: Ключ '" << key << "' не найден." << std::endl;
            sqlite3_finalize(stmt);
            return ""; // Возвращаем пустую строку если ключ не найден
        }
    }
    std::vector<std::pair<std::string, std::string>> getAll() {
        std::string sqlSelectAll = "SELECT key, value FROM kv_store;";
        sqlite3_stmt* stmt;
        std::vector<std::pair<std::string, std::string>> pairs;
        if (sqlite3_prepare_v2(db, sqlSelectAll.c_str(), -1, &stmt, nullptr) != SQLITE_OK) {
            std::cerr << "Ошибка подготовки SQL запроса: " << sqlite3_errmsg(db) << std::endl;
            throw std::runtime_error("Ошибка подготовки SQL запроса");
        }

        while (sqlite3_step(stmt) == SQLITE_ROW) {
            const unsigned char* key = sqlite3_column_text(stmt, 0);
            const unsigned char* value = sqlite3_column_text(stmt, 1);
            std::pair<std::string, std::string> key_and_value{
                reinterpret_cast<const char*>(key),
                reinterpret_cast<const char*>(value)
                };
            pairs.push_back(key_and_value);
        }
        sqlite3_finalize(stmt);        
        return pairs;
            

    }

    // Новый метод для получения случайных пар ключ-значение
    std::vector<std::pair<std::string, std::string>> getRandomPairs(int count) {
        std::vector<std::pair<std::string, std::string>> pairs;
        
        // Получаем все пары ключ-значение
        std::string sqlSelectAll = "SELECT key, value FROM kv_store;";
        sqlite3_stmt* stmt;

        if (sqlite3_prepare_v2(db, sqlSelectAll.c_str(), -1, &stmt, nullptr) != SQLITE_OK) {
            std::cerr << "Ошибка подготовки SQL запроса: " << sqlite3_errmsg(db) << std::endl;
            throw std::runtime_error("Ошибка подготовки SQL запроса");
        }

        while (sqlite3_step(stmt) == SQLITE_ROW) {
            const unsigned char* key = sqlite3_column_text(stmt, 0);
            const unsigned char* value = sqlite3_column_text(stmt, 1);
            pairs.emplace_back(reinterpret_cast<const char*>(key), reinterpret_cast<const char*>(value));
        }
        
        sqlite3_finalize(stmt);

        
        return pairs;
    }

private:
    sqlite3* db;

    void executeSQL(const char* sql) {
        char* errMsg = nullptr;
        if (sqlite3_exec(db, sql, nullptr, nullptr, &errMsg) != SQLITE_OK) {
            std::cerr << "Ошибка выполнения SQL: " << errMsg << std::endl;
            sqlite3_free(errMsg);
        }
    }
};