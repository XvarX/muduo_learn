#include "muduo/net/TcpServer.h"
#include "muduo/net/EventLoop.h"

using namespace muduo;
using namespace muduo::net;

class EchoServer {
public:
    EchoServer(EventLoop* loop, const InetAddress& addr):server_(loop, addr, "EchoServer") {
        server_.setMessageCallback(
            [](const TcpConnectionPtr& conn, Buffer*buf, Timestamp) {
                conn->send(buf);
            }
        );
    }

    void start() {
        server_.start();
    }

private:
    TcpServer server_;
    
};

int main() {
    EventLoop loop;
    InetAddress addr(8888);
    EchoServer server(&loop, addr);
    server.start();
    loop.loop();
}