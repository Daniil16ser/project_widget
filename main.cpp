#include "database3.h"
int main() {
    KeyValueStore kvStore("mydatabase.db");

    kvStore.add("key1", "10"); // Добавляем значение как строку
    kvStore.add("key2", "20");

    std::cout << "Получение значения по ключу 'key1': " << kvStore.get("key1") << std::endl;

    kvStore.remove("key1");
    std::cout << "После удаления ключа 'key1': " << kvStore.get("key1") << std::endl;

    // Попробуем получить значение по несуществующему ключу
    int result = kvStore.get("nonexistent_key");
    if (result == -1) {        std::cout << "Ключ не найден, возвращено значение: -1" << std::endl;
    }
    std::cout << result << std::endl;
    kvStore.add("key3", "value3");
    kvStore.printAll();

    return 0;
}
