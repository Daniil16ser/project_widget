#include "database3.h"
#include <iostream>
#include <vector>
int main() {
    KeyValueStore store("mydatabase.db");

    // Добавление пар ключ-значение
    store.add("key1", "value1");
    store.add("key2", "value2");
    store.add("key3", "value3");
    store.add("key4", "value4");
    
    std::cout << "Все пары после добавления:" << std::endl;
    std::vector<std::pair <std::string, std::string>> pairs = store.getAll(); // Печать всех пар
    for ( std::pair <std::string, std::string> pair : pairs){
        std::cout << pair.first;
        std::cout << pair.second;
    }
    std::cout << "_------------" << std::endl;

    // Получение значения по ключу
    std::string value = store.get("key2");
    if (!value.empty()) {
        std::cout << "Значение для 'key2': " << value << std::endl;
    }

    // Удаление пары по ключу
    store.remove("key3");
    std::cout << "Все пары после удаления 'key3':" << std::endl;
    

    // Получение случайных пар
    std::cout << "Случайные пары:" << std::endl;
    std::vector<std::pair< std::string, std::string>> parsik = store.getRandomPairs(1); // Получение 2 случайных пар
    // Инициализация генератора случайных чисел
    std::srand(static_cast<unsigned int>(std::time(0)));
    for ( std::pair <std::string, std::string> pairsk : parsik){
        std::cout << pairsk.first;
        std::cout << pairsk.second;
    }
    return 0;
}
