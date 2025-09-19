# 1. Используем официальный образ Ubuntu
FROM ubuntu:22.04

# Устанавливаем московское время и отключаем интерактив
ENV TZ=Europe/Moscow
ENV DEBIAN_FRONTEND=noninteractive

# 2. Устанавливаем зависимости для сборки Drogon и C++
RUN apt-get update && apt-get install -y \
    g++ \
    cmake \
    git \
    make \
    tzdata \
    libjsoncpp-dev \
    uuid-dev \
    openssl \
    zlib1g-dev \
    libssl-dev \
    libsqlite3-dev \
    libmariadb-dev \
    libmariadb-dev-compat \
    postgresql-all \
    && rm -rf /var/lib/apt/lists/*

RUN apt-get update && apt-get install -y graphviz

RUN apt-get update && apt-get install -y doxygen

RUN git clone https://github.com/drogonframework/drogon.git /tmp/drogon \
    && cd /tmp/drogon \
    && mkdir build && cd build \
    && cmake .. -DBUILD_DOXYGEN=OFF -DBUILD_EXAMPLES=OFF -DBUILD_TESTING=OFF \
    && make -j$(nproc) \
    && make install \
    && ldconfig

# 3. Создаем рабочую директорию внутри контейнера
WORKDIR /app

# 4. Копируем проект внутрь контейнера
COPY . .

# 5. Создаем папку для сборки
RUN mkdir -p build
WORKDIR /app/build

WORKDIR /app/build
RUN rm -rf * && cmake .. && make

# 6. Собираем проект
RUN cmake .. && make

# 7. Указываем порт, на котором работает Drogon
EXPOSE 8080

# 8. Запускаем приложение
CMD ["./my-drogon-app"]