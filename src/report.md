# Simple Docker

## Part 1. Готовый докер

##### Взять официальный докер образ с **nginx** и выкачать его при помощи `docker pull`
##### Проверить наличие докер образа через `docker images`
##### Запустить докер образ через `docker run -d [image_id|repository]`
##### Проверить, что образ запустился через `docker ps`
##### Посмотреть информацию о контейнере через `docker inspect [container_id|container_name]`

![первые команды](images/1-1.png)

##### По выводу команды определить и поместить в отчёт размер контейнера, список замапленных портов и ip контейнера

размер контейнера - 1.09kB (virtual 192MB)
список замапленных портов - "80/tcp"
ip контейнера - 172.17.0.2

##### Остановить докер образ через `docker stop [container_id|container_name]`
##### Проверить, что образ остановился через `docker ps`

![вторые команды](images/1_2.png)

##### Запустить докер с портами 80 и 443 в контейнере, замапленными на такие же порты на локальной машине, через команду *run*

![третьи команды](images/1_3.png)

##### Проверить, что в браузере по адресу *localhost:80* доступна стартовая страница **nginx**

![четвертые команды](images/1_4.png)

##### Перезапустить докер контейнер через `docker restart [container_id|container_name]`
##### Проверить любым способом, что контейнер запустился
![пятые команды](images/1_5.png)



## Part 2. Операции с контейнером

##### Прочитать конфигурационный файл *nginx.conf* внутри докер контейнера через команду *exec*

![Alt text](images/2_1.png)

##### Создать на локальной машине файл *nginx.conf*
##### Настроить в нем по пути */status* отдачу страницы статуса сервера **nginx**
##### Скопировать созданный файл *nginx.conf* внутрь докер образа через команду `docker cp`
##### Перезапустить **nginx** внутри докер образа через команду *exec*

![Alt text](images/2_2.png)

##### Проверить, что по адресу *localhost:80/status* отдается страничка со статусом сервера **nginx**

![Alt text](images/2_3.png)

##### Экспортировать контейнер в файл *container.tar* через команду *export*

##### Остановить контейнер
##### Удалить образ через `docker rmi [image_id|repository]`, не удаляя перед этим контейнеры
##### Удалить остановленный контейнер
##### Импортировать контейнер обратно через команду *import*

![Alt text](images/2_4.png)

##### Запустить импортированный контейнер

![Alt text](images/2_5.png)

##### Проверить, что по адресу *localhost:80/status* отдается страничка со статусом сервера **nginx**

![Alt text](images/2_6.png)

