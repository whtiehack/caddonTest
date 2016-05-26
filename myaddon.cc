#include <nan.h>


//1_hello_world
void Method(const Nan::FunctionCallbackInfo<v8::Value>& info) {
    info.GetReturnValue().Set(Nan::New("world111").ToLocalChecked());
}


//2_function_arguments
void Add(const Nan::FunctionCallbackInfo<v8::Value>& info) {
    
    if (info.Length() < 2) {
        Nan::ThrowTypeError("Wrong number of arguments");
        return;
    }
    
    if (!info[0]->IsNumber() || !info[1]->IsNumber()) {
        Nan::ThrowTypeError("Wrong arguments");
        return;
    }
    
    double arg0 = info[0]->NumberValue();
    double arg1 = info[1]->NumberValue();
    v8::Local<v8::Number> num = Nan::New(arg0 + arg1);
    
    info.GetReturnValue().Set(num);
}

//3_callbacks
void RunCallback(const Nan::FunctionCallbackInfo<v8::Value>& info) {
    if(!info[0]->IsFunction()){
        Nan::ThrowError("arg0 is not a function");
        return;
    }
    v8::Local<v8::Function> cb = info[0].As<v8::Function>();
    const unsigned argc = 1;
    v8::Local<v8::Value> argv[argc] = { Nan::New("hello world").ToLocalChecked() };
    Nan::MakeCallback(Nan::GetCurrentContext()->Global(), cb, argc, argv);
}

//4_object_factory
void CreateObject(const Nan::FunctionCallbackInfo<v8::Value>& info) {
    v8::Local<v8::Object> obj = Nan::New<v8::Object>();
    obj->Set(Nan::New("msg").ToLocalChecked(), info[0]->ToString());
    
    info.GetReturnValue().Set(obj);
}


//5_function_factory
void MyFunction(const Nan::FunctionCallbackInfo<v8::Value>& info) {
    info.GetReturnValue().Set(Nan::New("MyFunction hello world").ToLocalChecked());
}

//5_function_factory
void CreateFunction(const Nan::FunctionCallbackInfo<v8::Value>& info) {
    v8::Local<v8::FunctionTemplate> tpl = Nan::New<v8::FunctionTemplate>(MyFunction);
    v8::Local<v8::Function> fn = tpl->GetFunction();
    
    // omit this to make it anonymous
    fn->SetName(Nan::New("theFunctionMyName").ToLocalChecked());
    
    info.GetReturnValue().Set(fn);
}



void Init(v8::Local<v8::Object> exports, v8::Local<v8::Object> module) {
    exports->Set(Nan::New("hello").ToLocalChecked(),
                 Nan::New<v8::FunctionTemplate>(Method)->GetFunction());
    
    exports->Set(Nan::New("add").ToLocalChecked(),
                 Nan::New<v8::FunctionTemplate>(Add)->GetFunction());
    
    exports->Set(Nan::New("callback").ToLocalChecked(),
                 Nan::New<v8::FunctionTemplate>(RunCallback)->GetFunction());
    
    exports->Set(Nan::New("objectfactory").ToLocalChecked(),
                Nan::New<v8::FunctionTemplate>(CreateObject)->GetFunction());
    
    Nan::SetMethod(exports, "createFunction", CreateFunction);
}



NODE_MODULE(hello, Init)