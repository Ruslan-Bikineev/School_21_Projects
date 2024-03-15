#!/bin/bash
# Мануал
# https://antonputra.com/monitoring/install-prometheus-and-grafana-on-ubuntu/#install-node-exporter-on-ubuntu-2004

# Создаем системного пользователя для Node Exporter
sudo useradd \
    --system \
    --no-create-home \
    --shell /bin/false node_exporter
# Загружаем дваоичный файл
wget https://github.com/prometheus/node_exporter/releases/download/v1.6.1/node_exporter-1.6.1.linux-amd64.tar.gz
# Затем нам нужно извлечь из архива все файлы Node Exporter
tar -xvf node_exporter-1.6.1.linux-amd64.tar.gz
sudo mv node_exporter-1.6.1.linux-amd64/node_exporter /usr/local/bin/
rm -rf node_exporter*
# Проверка
node_exporter --version

touch node_exporter.service
echo "[Unit]
Description=Node Exporter
Wants=network-online.target
After=network-online.target

StartLimitIntervalSec=500
StartLimitBurst=5

[Service]
User=node_exporter
Group=node_exporter
Type=simple
Restart=on-failure
RestartSec=5s
ExecStart=/usr/local/bin/node_exporter \
    --collector.logind

[Install]
WantedBy=multi-user.target" >> node_exporter.service
sudo mv node_exporter.service /etc/systemd/system/node_exporter.service

sudo systemctl enable node_exporter
sudo systemctl start node_exporter
sudo systemctl status node_exporter

# Не забыть ввести
# sudo nano /etc/prometheus/prometheus.yml
#   - job_name: node_export
#     static_configs:
#       - targets: ["localhost:9100"]

# Проверка на корректность конфигурации
# promtool check config /etc/prometheus/prometheus.yml
# Можем использовать запрос POST для перезагрузки конфигурации
# curl -X POST http://localhost:9090/-/reload
