FROM ubuntu/nginx

WORKDIR /etc/nginx

COPY ./server/hello_world.c hello_world.c
COPY ./server/nginx.conf nginx.conf

RUN apt-get update \
  && apt-get install -y gcc libfcgi-dev libfcgi0ldbl curl \
  && gcc hello_world.c -lfcgi -o hello_world.fcgi \
  && useradd -d /home/alaskank -m -s /bin/bash alaskank \
  && chown -R alaskank:alaskank /etc/nginx \
  && chown -R alaskank:alaskank /var \
  && chown -R alaskank:alaskank /run \
  && chown -R alaskank:alaskank /home \
  && chmod u-s /usr/bin/newgrp \
  && chmod u-s /usr/bin/chsh \
  && chmod u-s /usr/bin/passwd \
  && chmod g-s /usr/bin/chage \
  && chmod u-s /usr/bin/chfn \
  && chmod u-s /usr/bin/mount \
  && chmod u-s /usr/bin/umount \
  && chmod u-s /usr/bin/gpasswd \
  && chmod u-s /usr/bin/su \
  && chmod g-s /usr/bin/wall \
  && chmod g-s /usr/bin/expiry \
  && chmod g-s /usr/sbin/pam_extrausers_chkpwd \
  && chmod g-s /usr/sbin/unix_chkpwd \
  && rm -rf /var/lib/apt/lists

USER alaskank

CMD ["sh", "-c", "nginx -g 'daemon off;' & ./hello_world.fcgi"]

HEALTHCHECK --interval=2s --timeout=5s --retries=3 CMD curl -f http://localhost:80 || exit 1
