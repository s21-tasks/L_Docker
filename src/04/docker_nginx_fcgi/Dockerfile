# Используем готовый образ с nginx в качестве базового образа
FROM nginx:latest

# Установка необходимых инструментов для сборки и установки spawn-fcgi
RUN apt-get update && apt-get install -y \
    build-essential \
    libfcgi-dev \
    spawn-fcgi \
    gcc 


# Собираем FastCGI сервер
WORKDIR /fastcgi-server

COPY hello.c /fastcgi-server

COPY start.sh /fastcgi-server

COPY ./nginx/nginx.conf /etc/nginx/nginx.conf

COPY ./nginx/fastcgi_params /etc/nginx/fastcgi_params


RUN gcc -o hello hello.c -lfcgi

EXPOSE 81


CMD spawn-fcgi -p 8080 -n ./hello & nginx -g "daemon off;"
