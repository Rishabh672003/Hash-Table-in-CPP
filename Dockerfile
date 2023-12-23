FROM alpine:latest
WORKDIR /app

RUN apk update
RUN apk add build-base cmake git

COPY . /app

RUN ["make", "builddeps"]
RUN ["make", "compile"]
RUN ["make", "run"]
