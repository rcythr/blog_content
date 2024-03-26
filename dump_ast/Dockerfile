FROM ubuntu:22.04

RUN apt update && \
    apt install -y \
        build-essential \
        clang \
        llvm-14-dev \
        libclang-14-dev

WORKDIR dump_ast

COPY . .

CMD ./run.sh
