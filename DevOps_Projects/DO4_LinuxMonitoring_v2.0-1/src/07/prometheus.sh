#!/bin/bash
# Мануал
# https://antonputra.com/monitoring/install-prometheus-and-grafana-on-ubuntu/#install-prometheus-on-ubuntu-2004
# https://www.youtube.com/watch?v=hePmCMmekmo

# Чтобы создать системного пользователя или системную учетную запись, выполните следующую команду:
sudo useradd \
    --system \
    --no-create-home \
    --shell /bin/false prometheus
# Команда wget для загрузки Prometheus
# Надо проверять актульную версию на этом сайте https://prometheus.io/download/
wget https://github.com/prometheus/prometheus/releases/download/v2.47.0/prometheus-2.47.0.linux-amd64.tar.gz
# Затем нам нужно извлечь из архива все файлы Prometheus
tar -xvf prometheus-2.47.0.linux-amd64.tar.gz
# Обычно к каталогу данных подключается диск. Для этого урока я просто создам /dataрежиссёра. Также вам понадобится папка для файлов конфигурации Prometheus.
sudo mkdir -p /data /etc/prometheus
# Теперь давайте изменим каталог на Prometheus и переместим несколько файлов.
cd prometheus-2.47.0.linux-amd64
# Прежде всего, давайте переместим prometheus двоичный файл и a promtoolв файл /usr/local/bin/. promtool используется для проверки файлов конфигурации и правил Prometheus.
sudo mv prometheus promtool /usr/local/bin/
# Перемещаем консольные библиотеки в каталог конфигурации Prometheus
sudo mv consoles/ console_libraries/ /etc/prometheus/
# Переходим к основным файлом конфигурации Prometheus.
sudo mv prometheus.yml /etc/prometheus/prometheus.yml
# Чтобы избежать проблем с разрешениями, вам необходимо установить правильное владение каталогом /etc/prometheus/и data.
sudo chown -R prometheus:prometheus /etc/prometheus/ /data/
# Удалаяем архив и папку Prometheus
cd && rm -rf prometheus*
# Проверка
prometheus --version

touch prometheus.service
echo "[Unit]
Description=Prometheus
Wants=network-online.target
After=network-online.target

StartLimitIntervalSec=500
StartLimitBurst=5

[Service]
User=prometheus
Group=prometheus
Type=simple
Restart=on-failure
RestartSec=5s
ExecStart=/usr/local/bin/prometheus \
  --config.file=/etc/prometheus/prometheus.yml \
  --storage.tsdb.path=/data \
  --web.console.templates=/etc/prometheus/consoles \
  --web.console.libraries=/etc/prometheus/console_libraries \
  --web.listen-address=0.0.0.0:9090 \
  --web.enable-lifecycle

[Install]
WantedBy=multi-user.target" >> prometheus.service
sudo mv prometheus.service /etc/systemd/system/prometheus.service

# Чтобы автоматически запустить Прометей после перезагрузки, запустите команду Enable
sudo systemctl enable prometheus
# Start prometheus
sudo systemctl start prometheus
# Check status prometheus
sudo systemctl status prometheus
