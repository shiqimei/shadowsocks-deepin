//
// Created by pikachu on 17-8-8.
//

#ifndef SHADOWSOCKS_CLIENT_GLOBAL_H
#define SHADOWSOCKS_CLIENT_GLOBAL_H
template<typename T>
class Singleton
{
public:
    static T* instance(){
        static T instance;
        return &instance;
    }

private:
    Singleton();
    ~Singleton();
    Singleton(const Singleton &);
    Singleton & operator = (const Singleton &);
};

#endif //SHADOWSOCKS_CLIENT_GLOBAL_H
