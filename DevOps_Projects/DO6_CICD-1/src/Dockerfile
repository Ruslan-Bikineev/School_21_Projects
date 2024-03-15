FROM ubuntu:22.04

RUN apt-get update \
  && apt-get install -y git curl gcc make nano clang-format openssh-server \
  && curl -L "https://packages.gitlab.com/install/repositories/runner/gitlab-runner/script.deb.sh" | bash \
  && apt-get install -y gitlab-runner \
  && rm -rf /var/lib/apt/lists 

CMD ["sh", "-c", "service ssh start && gitlab-runner run"]