FROM ubuntu:14.04
RUN apt-get update && apt-get install -y check make build-essential
CMD cd /usr/roman ; make test
