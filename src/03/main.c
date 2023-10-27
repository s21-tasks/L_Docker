#include <stdio.h>
#include <stdlib.h>
#include <fcgiapp.h>

int main(int argc, char *argv[]) {
  // Инициализируем структуру приложения FastCGI
  FCGX_Request request;
  FCGX_Init();

  // Обрабатываем запрос
  if (FCGX_InitRequest(&request, 0, 0) == 0) {
    // Отправляем ответ
    FCGX_FPrint(&request, "Content-type: text/html\r\n\r\n");
    FCGX_FPrint(&request, "<html><body><h1>Hello World!</h1></body></html>");
    FCGX_FinishRequest(&request);
  }

  // Выходим
  FCGX_Shutdown();
  return 0;
