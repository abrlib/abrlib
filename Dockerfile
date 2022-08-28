FROM ubuntu:latest

# Workaround https://unix.stackexchange.com/questions/2544/how-to-work-around-release-file-expired-problem-on-a-local-mirror
RUN echo "Acquire::Check-Valid-Until \"false\";\nAcquire::Check-Date \"false\";" | cat > /etc/apt/apt.conf.d/10no--check-valid-until

# environment set
ARG DEBIAN_FRONTEND=noninteractive
ENV TERM xterm-256color
ENV ABRUSLIB_ROOT /var/local/abruslib
ENV PATH "${PATH}:${ABRUSLIB_ROOT}"
SHELL ["/bin/bash", "-c"] 

# requrire packages instalation
RUN apt-get update && apt-get install -y \
    python3 \
    python3-pip \
    python2 \
    build-essential \
    cmake \
    ninja-build \
    uncrustify \
    sudo \
    less \
    vim \
    git \
    tree
RUN pip3 install termcolor

# user configuration
RUN useradd -ms /bin/bash abrus
RUN usermod -aG sudo abrus
RUN echo '%sudo ALL=(ALL) NOPASSWD:ALL' >> /etc/sudoers
USER abrus
WORKDIR /var/local/abruslib

CMD bash
