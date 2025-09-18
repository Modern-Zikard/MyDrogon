#include <drogon/drogon.h>

int main() {
    // Настройка сервера
    drogon::app().loadConfigFile("config.json").run(); // Запускаем на порту 8080

    return 0;
}
//#include <drogon/drogon.h>
//#include <iostream>
//
//
//int main() {
//    // Настройка сервера
//   
//    drogon::app().loadConfigFile("config.json")
//        .registerHandler("/", [](const drogon::HttpRequestPtr&, std::function<void(const drogon::HttpResponsePtr&)>&& callback)
//            {
//                auto resp = drogon::HttpResponse::newHttpResponse();
//                resp->setBody("Hello from Drogon!");
//                callback(resp);
//            })
//        .run();
//}
