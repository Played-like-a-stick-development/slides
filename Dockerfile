FROM ubuntu:focal
WORKDIR /slides

COPY . .

ARG DEBIAN_FRONTEND=noninteractive
RUN apt update
RUN apt install -y make gcc g++ libncurses5-dev libncursesw5-dev libsdl2-2.0-0 libsdl2-ttf-2.0-0 libsdl2-dev libsdl2-ttf-dev

RUN make

CMD ["/slides/main"]