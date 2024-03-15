#include <stdio.h>
#include <fcgiapp.h> 
#include <fcgi_config.h>

#define SOCKET_PATH "127.0.0.1:8080" 

int main() {
  // Инициализация библилиотеки 
  FCGX_Init();
  int socketId = FCGX_OpenSocket(SOCKET_PATH, 100); 
  FCGX_Request request; 
  // Инициализируем структуру запроса
  FCGX_InitRequest(&request, socketId, 0);
  // Запускаем цикл обработки запросов
  while (FCGX_Accept_r(&request) >= 0) {
    FCGX_FPrintF(request.out, "Content-Type: text/html\n\n");
    FCGX_FPrintF(request.out, "hello world");
    // Завершаем запрос
    FCGX_Finish_r(&request);
  }
  return 0;
}