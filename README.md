# 🛰 AODV Routing Protocol Implementation

## 📌 Overview

The **Networking Application** implements the **AODV (Ad-hoc On-Demand Distance Vector) routing protocol** to simulate a decentralized, peer-to-peer network. This project enables multiple nodes to communicate, discover routes dynamically, and handle failures using **UDP sockets**. 

## 🚀 Features

- **AODV Protocol Implementation**
  - Route Discovery (`RREQ`, `RREP`)
  - Route Maintenance (`RERR`)
  - Routing Table Management
- **UDP-based Communication**
  - Uses **sockets** for real-time message exchange.
- **Docker Support**
  - Simulate multiple nodes using **Docker containers**.
- **Environment Variable Configuration**
  - Configure each node dynamically via `NODE_ID` and `NODE_IP`.

---

## 🏗 Project Structure

aetherNetwork/
│── src/
│   ├── main.c
│   ├── aodv.c
│   ├── aodv.h
│   ├── network.c
│   ├── network.h
│   ├── task_manager.c
│   ├── task_manager.h
│── CMakeLists.txt
│── Dockerfile




## 🛠 Installation & Setup

### 🔹 **1. Build and Run Locally (Linux/WSL)**

Ensure you have **GCC, CMake, and Make** installed.  

```bash
# Clone the repository
git clone https://github.com/your-repo/aetherNetwork.git
cd aetherNetwork

# Build the application
mkdir build && cd build
cmake ..
make

# Run a node (Example: Node 1)
export NODE_ID=1
export NODE_IP="127.0.0.1"
./node1

```
### 🔹 **2. Run Using Docker (Recommended)**

Simulate multiple nodes using Docker containers.

```bash
# Step 1: Build the Docker Image
docker build -t aether-networking .

# Step 2: Create a Custom Docker Network
docker network create --subnet=172.18.0.0/16 aodv_net

# Step 3: Run Multiple Nodes (Simulating a Network)
# Run Node 1
docker run -it --rm --net aodv_net --ip 172.18.0.2 -e NODE_ID=1 -e NODE_IP=172.18.0.2 aether-networking

# Run Node 2
docker run -it --rm --net aodv_net --ip 172.18.0.3 -e NODE_ID=2 -e NODE_IP=172.18.0.3 aether-networking

# Run Node 3
docker run -it --rm --net aodv_net --ip 172.18.0.4 -e NODE_ID=3 -e NODE_IP=172.18.0.4 aether-networking
```

## How It Works
Each node initializes with a unique NODE_ID and NODE_IP. Nodes exchange messages over UDP.

## Route Discovery
Node A sends an RREQ message to find a path to Node B.
Intermediate nodes forward the request if no route exists.
If Node B receives RREQ, it responds with an RREP (Route Reply).
## Route Error Handling
If a link fails, affected nodes send an RERR (Route Error) to notify others.
The routing table is updated dynamically.





