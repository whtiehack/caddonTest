//
//  Header.h
//  binding
//
//  Created by mac on 16/6/2.
//
//

#ifndef MYOBJECT_H
#define MYOBJECT_H
//6_object_wrap
#include <nan.h>

class MyObject : public Nan::ObjectWrap {
public:
    static void Init(v8::Local<v8::Object> exports);
    static v8::Local<v8::Object> NewInstance(v8::Local<v8::Value> arg);
    
    double Val() const { return value_; }
private:
    explicit MyObject(double value = 0);
    ~MyObject();
    
    static void New(const Nan::FunctionCallbackInfo<v8::Value>& info);
    static void GetValue(const Nan::FunctionCallbackInfo<v8::Value>& info);
    static void PlusOne(const Nan::FunctionCallbackInfo<v8::Value>& info);
    static void Multiply(const Nan::FunctionCallbackInfo<v8::Value>& info);
    static Nan::Persistent<v8::Function> constructor;
    double value_;
};

#endif