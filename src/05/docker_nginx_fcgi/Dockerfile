# Используем готовый образ с nginx в качестве базового образа
FROM nginx:1.20.1

# Установка необходимых инструментов для сборки и установки spawn-fcgi
RUN apt-get update && apt-get install -y \
    build-essential \
    libfcgi-dev \
    spawn-fcgi \
    gcc && \
    rm -rf /var/lib/apt/lists

RUN set -x && \
    addgroup --system --gid 101 nginx && \
    adduser --system --disabled-login --ingroup nginx --no-create-home --home /nonexistent --gecos "nginx user" --shell /bin/false --uid 101 nginx && \
    apt-get update && \
    apt-get install --no-install-recommends --no-install-suggests -y gnupg1 ca-certificates && \
    NGINX_GPGKEY=573BFD6B3D8FBC641079A6ABABF5BD827BD9BF62; \
    found=''; \
    for server in \
        ha.pool.sks-keyservers.net \
        hkp://keyserver.ubuntu.com:80 \
        hkp://p80.pool.sks-keyservers.net:80 \
        pgp.mit.edu; do \
        echo "Fetching GPG key $NGINX_GPGKEY from $server"; \
        apt-key adv --keyserver "$server" --keyserver-options timeout=10 --recv-keys "$NGINX_GPGKEY" && found=yes && break; \
    done; \
    test -z "$found" && echo >&2 "error: failed to fetch GPG key $NGINX_GPGKEY" && exit 1; \
    apt-get remove --purge --auto-remove -y gnupg1 && rm -rf /var/lib/apt/lists/*

# Создаем пользователя для контейнера
RUN useradd -r -u 1001 myuser
USER myuser

# Копируем файлы в образ
WORKDIR /fastcgi-server
COPY hello.c /fastcgi-server

COPY ./nginx/nginx.conf /etc/nginx/nginx.conf
COPY ./nginx/fastcgi_params /etc/nginx/fastcgi_params

# Собираем FastCGI сервер
RUN gcc -o hello hello.c -lfcgi

# HEALTHCHECK инструкция
HEALTHCHECK CMD curl --fail http://localhost:81/ || exit 1

# Запускаем FastCGI сервер с помощью spawn-fcgi на порту 8080
CMD spawn-fcgi -p 8080 -n ./hello && nginx -g "daemon off;"
