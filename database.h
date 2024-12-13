#include <iostream>
#include "sqlite3.h"

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

    int get(const std::string& key) {
        std::string sqlSelect = "SELECT value FROM kv_store WHERE key = ?;";
        sqlite3_stmt* stmt;

        if (sqlite3_prepare_v2(db, sqlSelect.c_str(), -1, &stmt, nullptr) != SQLITE_OK) {
            std::cerr << "Ошибка подготовки SQL запроса: " << sqlite3_errmsg(db) << std::endl;
            return -1; // Возвращаем -1 в случае ошибки
        }

        sqlite3_bind_text(stmt, 1, key.c_str(), -1, SQLITE_STATIC);

        if (sqlite3_step(stmt) == SQLITE_ROW) {
            const unsigned char* text = sqlite3_column_text(stmt, 0);
            int value = std::stoi(reinterpret_cast<const char*>(text)); // Преобразуем значение в int
            sqlite3_finalize(stmt);
            return value; // Возвращаем найденное значение
        } else {
            std::cerr << "Предупреждение: Ключ '" << key << "' не найден." << std::endl;
            sqlite3_finalize(stmt);
            return -1; // Возвращаем -1 если ключ не найден
        }
    }

    void printAll() {
        std::string sqlSelectAll = "SELECT key, value FROM kv_store;";
        sqlite3_stmt* stmt;

        if (sqlite3_prepare_v2(db, sqlSelectAll.c_str(), -1, &stmt, nullptr) != SQLITE_OK) {
            std::cerr << "Ошибка подготовки SQL запроса: " << sqlite3_errmsg(db) << std::endl;
            return;
        }

        while (sqlite3_step(stmt) == SQLITE_ROW) {
            const unsigned char* key = sqlite3_column_text(stmt, 0);
            const unsigned char* value = sqlite3_column_text(stmt, 1);
            std::cout << "Ключ: " << reinterpret_cast<const char*>(key)
                      << ", Значение: " << reinterpret_cast<const char*>(value) << std::endl;
        }

        sqlite3_finalize(stmt);
    }

private:
    sqlite3* db;

    void executeSQL(const char* sql) {
        char* errMsg = nullptr;        if (sqlite3_exec(db, sql, nullptr, nullptr, &errMsg) != SQLITE_OK) {
            std::cerr << "Ошибка выполнения SQL: " << errMsg << std::endl;
            sqlite3_free(errMsg);
        }
    }
};
/*
int main() {
    KeyValueStore kvStore("mydatabase.db");

    kvStore.add("key1", "10");
    kvStore.add("key2", "20");

    kvStore.printAll(); // Вывод всех ключей и значений

    kvStore.remove("key1");
    kvStore.printAll(); // Проверка после удаления

    return 0;
}
*/
