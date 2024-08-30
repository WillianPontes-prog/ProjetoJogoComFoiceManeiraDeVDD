#ifndef OBSERVER_H
#define OBSERVER_H

class Observer {
public:
    virtual ~Observer() {}
    virtual void onNotify(int tecla) = 0;  // M�todo chamado quando um evento ocorre
};

#endif // OBSERVER_H
