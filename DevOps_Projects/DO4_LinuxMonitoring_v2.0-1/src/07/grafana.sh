#!/bin/bash
# Мануал 
# https://grafana.com/grafana/download

sudo apt-get install -y adduser libfontconfig1 musl
# Возможно скачать не удастся из-за санкций
wget https://dl.grafana.com/enterprise/release/grafana-enterprise_10.1.2_amd64.deb
sudo dpkg -i grafana-enterprise_10.0.3_amd64.deb
sudo systemctl enable grafana-server
sudo systemctl start grafana-server
sudo systemctl status grafana-server
touch datasources.yaml

echo "apiVersion: 1

datasources:
  - name: Prometheus
    type: prometheus
    url: http://localhost:9090
    isDefault: true" >> datasources.yaml

sudo mv datasources.yaml /etc/grafana/provisioning/datasources/datasources.yaml
sudo systemctl restart grafana-server
