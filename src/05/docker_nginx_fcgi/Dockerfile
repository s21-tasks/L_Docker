# Используем готовый образ с nginx в качестве базового образа
FROM nginx:1.20.1

# Установка необходимых инструментов для сборки и установки spawn-fcgi
RUN apt-get update && apt-get install -y \
    build-essential \
    libfcgi-dev \
    spawn-fcgi \
    gcc && \
    rm -rf /var/lib/apt/lists

# Создаем пользователя для контейнера
RUN useradd -r -u 1001 myuser
USER myuser

# Копируем файлы в образ
WORKDIR /fastcgi-server
COPY hello.c /fastcgi-server
COPY start.sh /fastcgi-server

COPY ./nginx/nginx.conf /etc/nginx/nginx.conf
COPY ./nginx/fastcgi_params /etc/nginx/fastcgi_params

# Собираем FastCGI сервер
RUN gcc -o hello hello.c -lfcgi

# HEALTHCHECK инструкция
HEALTHCHECK CMD curl --fail http://localhost:81/ || exit 1

# Запускаем FastCGI сервер с помощью spawn-fcgi на порту 8080
CMD spawn-fcgi -p 8080 -n ./hello && nginx -g "daemon off;"
