FROM ubuntu:16.04
RUN apt-get update
RUN	apt-get -y upgrade
RUN apt-get install libreadline6 libreadline6-dev
RUN apt-get install -y g++ make valgrind

COPY . .
