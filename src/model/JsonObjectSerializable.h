//
// Created by pikachu on 17-8-19.
//

#ifndef SHADOWSOCKS_CLIENT_JSONOBJECTSERIALIZABLE_H
#define SHADOWSOCKS_CLIENT_JSONOBJECTSERIALIZABLE_H

class JsonObjectSerializable {
public:
    virtual QJsonObject toJsonObject() = 0;

    virtual void fromJsonObject(QJsonObject jsonObject)=0;
};

#endif //SHADOWSOCKS_CLIENT_JSONOBJECTSERIALIZABLE_H
