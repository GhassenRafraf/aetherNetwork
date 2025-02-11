# Use an Ubuntu base image
FROM ubuntu:20.04

# Install required packages
RUN apt-get update && apt-get install -y \
    build-essential \
    cmake \
    iproute2 \
    net-tools

# Set the working directory
WORKDIR /app

# Copy the project source code into the container
COPY . /app

# Build the application
RUN mkdir build && cd build && cmake .. && make

# Expose the UDP port (if needed for testing from outside the container)
EXPOSE 5555

# Default command: you can override the NODE_ID and NODE_IP when running the container.
CMD ["./build/node1", "1", "192.168.1.1"]
