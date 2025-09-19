#include <drogon/drogon.h>

int main() {
    // Настройка сервера
    drogon::app().loadConfigFile("config.json").run(); // Запускаем на порту 8080

    return 0;
}

