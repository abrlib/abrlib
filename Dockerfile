FROM ubuntu:latest

# Workaround https://unix.stackexchange.com/questions/2544/how-to-work-around-release-file-expired-problem-on-a-local-mirror
RUN echo "Acquire::Check-Valid-Until \"false\";\nAcquire::Check-Date \"false\";" | cat > /etc/apt/apt.conf.d/10no--check-valid-until

ARG DEBIAN_FRONTEND=noninteractive
ENV TERM xterm-256color
SHELL ["/bin/bash", "-c"] 

# install requrire packages
RUN apt-get update && apt-get install -y \
    python3 \
    python3-pip \
    build-essential \
    cmake \
    ninja-build \
    uncrustify \
    sudo \
    less \
    vim 
RUN pip3 install termcolor

RUN useradd -ms /bin/bash abr-user
RUN usermod -aG sudo abr-user
RUN echo '%sudo ALL=(ALL) NOPASSWD:ALL' >> /etc/sudoers

USER abr-user
WORKDIR /var/local/abrlib
CMD bash
