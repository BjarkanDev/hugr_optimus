FROM ubuntu:24.04
RUN apt-get -y update && apt-get install -y --no-install-recommends python3

WORKDIR /hugr_optimus

COPY . . 


