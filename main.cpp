#include <drogon/drogon.h>

int main() {
    // ��������� �������
    drogon::app().loadConfigFile("config.json").run(); // ��������� �� ����� 8080

    return 0;
}
//#include <drogon/drogon.h>
//#include <iostream>
//
//
//int main() {
//    // ��������� �������
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
