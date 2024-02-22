FROM nginx

WORKDIR /etc/nginx

COPY hello_world.c hello_world.c
COPY nginx.conf nginx.conf

RUN apt-get update \
  && apt-get install -y gcc libfcgi-dev libfcgi0ldbl \
  && gcc hello_world.c -lfcgi -o hello_world.fcgi

CMD ["sh", "-c", "nginx -g 'daemon off;' & ./hello_world.fcgi"]
