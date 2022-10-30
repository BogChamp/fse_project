FROM ubuntu:20.04


ENV DEBIAN_FRONTEND=noninteractive

RUN apt-get update && apt-get install -y --no-install-recommends \ 
		build-essential \
		libgtest-dev \
		cmake \
		git \
		vim \
		python3.9 \
		python3-pip \
	&& apt-get clean

RUN pip install gcovr

RUN git clone https://github.com/BogChamp/fse_project.git && cd fse_project
WORKDIR /fse_project

RUN make test
