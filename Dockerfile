FROM ubuntu:22.10
LABEL MAINTAINER="YuukiTakao" 

WORKDIR /projects/9cc

RUN apt-get update  && \
    apt-get upgrade && \
    apt-get -y install build-essential vim man git
