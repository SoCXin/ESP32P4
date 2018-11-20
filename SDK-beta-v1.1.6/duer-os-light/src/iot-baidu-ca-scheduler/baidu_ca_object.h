// Copyright 2017 Baidu Inc. All Rights Reserved.
// Author: Su Hao (suhao@baidu.com)
//
// Description: Object

#ifndef BAIDU_IOT_TINYDU_IOT_OS_SRC_IOT_BAIDU_CA_SCHEDULER_BAIDU_CA_OBJECT_H
#define BAIDU_IOT_TINYDU_IOT_OS_SRC_IOT_BAIDU_CA_SCHEDULER_BAIDU_CA_OBJECT_H

#include <stddef.h>

struct baidu_json;

namespace duer {

class Object {
public:

    Object();

    ~Object();

    void reset();

    void putInt(const char* key, int value);

    void putDouble(const char* key, double value);

    void putString(const char* key, const char* value);

    // Note: the life time of value should be longer or equal this
    void putObject(const char* key, const Object& value);

    void putIntArray(const char* key, int value[], size_t length);

    void putDoubleArray(const char* key, double value[], size_t length);

    void putStringArray(const char* key, const char* value[], size_t length);

    void putObjectArray(const char* key, Object value[], size_t length);

    // the owner of object will be transfered to this.
    // there should no other Object control the life of object
    void receiveObject(const char* key, baidu_json* object);

    // give up the ownership of _data, and reset _data to a new one
    baidu_json* releaseObject();

    const char* toString();

private:

    Object(const Object& other);

    Object& operator =(const Object& other);

    baidu_json*     _data;
    char*           _string;
};

} // namespace duer

#endif // BAIDU_IOT_TINYDU_IOT_OS_SRC_IOT_BAIDU_CA_SCHEDULER_BAIDU_CA_OBJECT_H
