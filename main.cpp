#include <drogon/drogon.h>

int main() {
    // ��������� �������
    drogon::app().loadConfigFile("config.json").run(); // ��������� �� ����� 8080

    return 0;
}

