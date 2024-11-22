FROM golang:1.23

WORKDIR /usr/src/app

RUN go install github.com/air-verse/air@latest

COPY . .

RUN go mod tidy
