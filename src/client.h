#ifndef MERE_MESSAGE_CLIENT_H
#define MERE_MESSAGE_CLIENT_H

#include "global.h"
#include "messenger.h"
#include "sender.h"

namespace Mere
{
namespace Message
{

class MERE_MESSAGE_LIB_SPEC Client : public Sender
{
    Q_OBJECT
public:
    virtual ~Client();
    explicit Client(const std::string &path, QObject *parent = nullptr);
    explicit Client(const char *path, QObject *parent = nullptr);

    int join();
    int done();

    void ping();
    void send(const std::string &message) override;

signals:
    void call(const int &pid);

    void ping(const int &pid);
    void pong(const int &pid);

    void post(const mid_t &id);

    void message(const std::string &message);
    void message(const Mere::Message::Message &message);

    void seen(const pid_t &pid, const mid_t &id);
    void ackn(const pid_t &pid, const method_t &method);

private:
//    bool m_ready = false;
//    Messenger *m_messenger;

    class ClientPrivate;
    ClientPrivate *d_ptr;
};

}
}

#endif // MERE_MESSAGE_CLIENT_H
