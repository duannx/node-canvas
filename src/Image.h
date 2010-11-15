
//
// Image.h
//
// Copyright (c) 2010 LearnBoost <tj@learnboost.com>
//

#ifndef __NODE_IMAGE_H__
#define __NODE_IMAGE_H__

#include "Canvas.h"

using namespace v8;

class Image: public node::ObjectWrap {
  public:
    char *filename;
    int width, height;
    Persistent<Function> onload;
    Persistent<Function> onerror;
    static void Initialize(Handle<Object> target);
    static Handle<Value> New(const Arguments &args);
    static Handle<Value> GetSrc(Local<String> prop, const AccessorInfo &info);
    static Handle<Value> GetOnload(Local<String> prop, const AccessorInfo &info);
    static Handle<Value> GetOnerror(Local<String> prop, const AccessorInfo &info);
    static Handle<Value> GetComplete(Local<String> prop, const AccessorInfo &info);
    static Handle<Value> GetWidth(Local<String> prop, const AccessorInfo &info);
    static Handle<Value> GetHeight(Local<String> prop, const AccessorInfo &info);
    static void SetSrc(Local<String> prop, Local<Value> val, const AccessorInfo &info);
    static void SetOnload(Local<String> prop, Local<Value> val, const AccessorInfo &info);
    static void SetOnerror(Local<String> prop, Local<Value> val, const AccessorInfo &info);
    inline cairo_surface_t *surface(){ return _surface; } 
    inline uint8_t *data(){ return cairo_image_surface_get_data(_surface); } 
    inline int stride(){ return cairo_image_surface_get_stride(_surface); } 
    cairo_status_t loadSurface();
    void error(Local<Value>);
    void loadSync();
    void loaded();
    void load();
    Image();

    enum {
        DEFAULT
      , LOADING
      , COMPLETE
    } state;
  
  private:
    cairo_surface_t *_surface;
    ~Image();
};

#endif