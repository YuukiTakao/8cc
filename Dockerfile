FROM ubuntu:22.10
LABEL MAINTAINER="YuukiTakao" 

WORKDIR /projects/9cc

RUN apt-get update  && \
    apt-get upgrade && \
    apt-get -y install gcc make git binutils libc6-dev
