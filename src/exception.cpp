/**
 * Autogenerated by Pebble Compiler (1.0.0.652 11:33:50 Sep 20 2017)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 * Copyright (c) 2015, Tencent Inc. All rights reserved.
 */
#include <algorithm>
#include <ostream>

#include "dr/common/to_string.h"
#include "platform.h"
#include "exception.h"

namespace pebble {


Exception::~Exception() throw() {
}


void Exception::__set_message(const std::string& val) {
    this->message = val;
}

void Exception::__set_type(const int32_t val) {
    this->type = val;
}

const char* Exception::ascii_fingerprint = "EEBC915CE44901401D881E6091423036";
const uint8_t Exception::binary_fingerprint[16] = {0xEE, 0xBC, 0x91, 0x5C, 0xE4, 0x49, 0x01, 0x40, 0x1D, 0x88, 0x1E, 0x60, 0x91, 0x42, 0x30, 0x36};

uint32_t Exception::read(::pebble::dr::protocol::TProtocol* iprot) {

    uint32_t xfer = 0;
    std::string fname;
    ::pebble::dr::protocol::TType ftype;
    int16_t fid;

    xfer += iprot->readStructBegin(fname);

    using ::pebble::dr::protocol::TProtocolException;


    while (true)
    {
        xfer += iprot->readFieldBegin(fname, ftype, fid);
        if (ftype == ::pebble::dr::protocol::T_STOP) {
                break;
        }
        if (fid == -1) {
            if (fname == "message") {
                fid = 1;
            }
            else if (fname == "type") {
                fid = 2;
            }
        }
        switch (fid)
        {
            case 1:
                if (ftype == ::pebble::dr::protocol::T_NULL || ftype == ::pebble::dr::protocol::T_STRING) {
                    xfer += iprot->readString(this->message);
                    this->__isset.message = true;
                } else {
                    xfer += iprot->skip(ftype);
                }
                break;
            case 2:
                if (ftype == ::pebble::dr::protocol::T_NULL || ftype == ::pebble::dr::protocol::T_I32) {
                    xfer += iprot->readI32(reinterpret_cast<int32_t&>(this->type));
                    this->__isset.type = true;
                } else {
                    xfer += iprot->skip(ftype);
                }
                break;
            default:
                xfer += iprot->skip(ftype);
                break;
        }
        xfer += iprot->readFieldEnd();
    }

    xfer += iprot->readStructEnd();

    return xfer;
}

uint32_t Exception::write(::pebble::dr::protocol::TProtocol* oprot) const {
    uint32_t xfer = 0;
    oprot->incrementRecursionDepth();
    xfer += oprot->writeStructBegin("Exception");

    xfer += oprot->writeFieldBegin("message", ::pebble::dr::protocol::T_STRING, 1);
    xfer += oprot->writeString(this->message);
    xfer += oprot->writeFieldEnd();

    xfer += oprot->writeFieldBegin("type", ::pebble::dr::protocol::T_I32, 2);
    xfer += oprot->writeI32(static_cast<int32_t>(this->type));
    xfer += oprot->writeFieldEnd();

    xfer += oprot->writeFieldStop();
    xfer += oprot->writeStructEnd();
    oprot->decrementRecursionDepth();
    return xfer;
}

void swap(Exception &a, Exception &b) {
    using ::std::swap;
    swap(a.message, b.message);
    swap(a.type, b.type);
    swap(a.__isset, b.__isset);
}

Exception::Exception(const Exception& other0) {
    message = other0.message;
    type = other0.type;
    __isset = other0.__isset;
}
Exception& Exception::operator=(const Exception& other1) {
    message = other1.message;
    type = other1.type;
    __isset = other1.__isset;
    return *this;
}
std::ostream& operator<<(std::ostream& out, const Exception& obj) {
    using pebble::dr::to_string;
    out << "Exception(";
    out << "message=" << to_string(obj.message);
    out << ", " << "type=" << to_string(obj.type);
    out << ")";
    return out;
}

} // namespace pebble
