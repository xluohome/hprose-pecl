/**********************************************************\
|                                                          |
|                          hprose                          |
|                                                          |
| Official WebSite: http://www.hprose.com/                 |
|                   http://www.hprose.org/                 |
|                                                          |
\**********************************************************/

/**********************************************************\
 *                                                        *
 * hprose_writer.c                                        *
 *                                                        *
 * hprose writer for pecl source file.                    *
 *                                                        *
 * LastModified: Mar 16, 2015                             *
 * Author: Ma Bingyao <andot@hprose.com>                  *
 *                                                        *
\**********************************************************/

#include "hprose_writer.h"

ZEND_METHOD(hprose_writer, __construct) {
    zval *obj = NULL;
    zend_bool simple = 0;
    HPROSE_OBJECT_INTERN(writer);
    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|b", &obj, &simple) == SUCCESS) {
        intern->_this = hprose_writer_create(HPROSE_GET_OBJECT_P(bytes_io, obj)->_this, simple);
    }
}

ZEND_METHOD(hprose_writer, __destruct) {
    HPROSE_OBJECT_INTERN(writer);
    if (intern->_this) {
        hprose_writer_free(intern->_this);
        intern->_this = NULL;
    }
}

ZEND_METHOD(hprose_writer, serialize) {
    zval *val = NULL;
    HPROSE_THIS(writer);
    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z!", &val) == SUCCESS) {
        hprose_writer_serialize(_this, val TSRMLS_CC);
    }
}

ZEND_METHOD(hprose_writer, writeInteger) {
    long i;
    HPROSE_THIS(writer);
    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "l", &i) == SUCCESS) {
        hprose_writer_write_long(_this, i);
    }
}

ZEND_METHOD(hprose_writer, writeDouble) {
    double d;
    HPROSE_THIS(writer);
    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "d", &d) == SUCCESS) {
        hprose_writer_write_double(_this, d);
    }
}

ZEND_METHOD(hprose_writer, writeNaN) {
    HPROSE_THIS(writer);
    hprose_writer_write_nan(_this);
}

ZEND_METHOD(hprose_writer, writeInfinity) {
    zend_bool positive = 1;
    HPROSE_THIS(writer);
    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|b", &positive) == SUCCESS) {
        hprose_writer_write_infinity(_this, positive);
    }
}

ZEND_METHOD(hprose_writer, writeNull) {
    HPROSE_THIS(writer);
    hprose_writer_write_null(_this);
}

ZEND_METHOD(hprose_writer, writeEmpty) {
    HPROSE_THIS(writer);
    hprose_writer_write_empty(_this);
}

ZEND_METHOD(hprose_writer, writeBoolean) {
    zend_bool b = 1;
    HPROSE_THIS(writer);
    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "b", &b) == SUCCESS) {
        hprose_writer_write_bool(_this, b);
    }
}

ZEND_METHOD(hprose_writer, writeUTF8Char) {
    zval *uc = NULL;
    HPROSE_THIS(writer);
    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &uc) == SUCCESS) {
        hprose_writer_write_utf8char(_this, uc);
    }
}

ZEND_METHOD(hprose_writer, writeString) {
    zval *s = NULL;
    HPROSE_THIS(writer);
    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &s) == SUCCESS) {
        hprose_writer_write_string(_this, s);
    }
}

ZEND_METHOD(hprose_writer, writeStringWithRef) {
    zval *s = NULL;
    HPROSE_THIS(writer);
    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &s) == SUCCESS) {
        hprose_writer_write_string_with_ref(_this, s);
    }    
}

ZEND_METHOD(hprose_writer, writeBytes) {
    zval *bytes = NULL;
    HPROSE_THIS(writer);
    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &bytes) == SUCCESS) {
        hprose_writer_write_bytes(_this, bytes);
    }    
}

ZEND_METHOD(hprose_writer, writeBytesWithRef) {
    zval *bytes = NULL;
    HPROSE_THIS(writer);
    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &bytes) == SUCCESS) {
        hprose_writer_write_bytes_with_ref(_this, bytes);
    }
}

ZEND_METHOD(hprose_writer, writeBytesIO) {
    zval *stream = NULL;
    HPROSE_THIS(writer);
    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "o", &stream) == SUCCESS) {
        hprose_writer_write_bytes_io(_this, stream TSRMLS_CC);
    }    
}

ZEND_METHOD(hprose_writer, writeBytesIOWithRef) {
    zval *stream = NULL;
    HPROSE_THIS(writer);
    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "o", &stream) == SUCCESS) {
        hprose_writer_write_bytes_io_with_ref(_this, stream TSRMLS_CC);
    }
}

ZEND_METHOD(hprose_writer, writeDateTime) {
    zval *dt = NULL;
    HPROSE_THIS(writer);
    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "o", &dt) == SUCCESS) {
        hprose_writer_write_datetime(_this, dt TSRMLS_CC);
    }    
}

ZEND_METHOD(hprose_writer, writeDateTimeWithRef) {
    zval *dt = NULL;
    HPROSE_THIS(writer);
    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "o", &dt) == SUCCESS) {
        hprose_writer_write_datetime_with_ref(_this, dt TSRMLS_CC);
    }
}

ZEND_METHOD(hprose_writer, writeArray) {
    zval *arr = NULL;
    HPROSE_THIS(writer);
    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "a", &arr) == SUCCESS) {
        hprose_writer_write_array(_this, arr TSRMLS_CC);
    }
}

ZEND_METHOD(hprose_writer, writeAssocArray) {
    zval *arr = NULL;
    HPROSE_THIS(writer);
    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "a", &arr) == SUCCESS) {
        hprose_writer_write_assoc_array(_this, arr TSRMLS_CC);
    }
}

ZEND_METHOD(hprose_writer, writeList) {
    zval *list = NULL;
    HPROSE_THIS(writer);
    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "o", &list) == SUCCESS) {
        hprose_writer_write_list(_this, list TSRMLS_CC);
    }
}

ZEND_METHOD(hprose_writer, writeListWithRef) {
    zval *list = NULL;
    HPROSE_THIS(writer);
    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "o", &list) == SUCCESS) {
        hprose_writer_write_list_with_ref(_this, list TSRMLS_CC);
    }
}

ZEND_METHOD(hprose_writer, writeMap) {
    zval *map = NULL;
    HPROSE_THIS(writer);
    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "o", &map) == SUCCESS) {
        hprose_writer_write_map(_this, map TSRMLS_CC);
    }
}

ZEND_METHOD(hprose_writer, writeMapWithRef) {
    zval *map = NULL;
    HPROSE_THIS(writer);
    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "o", &map) == SUCCESS) {
        hprose_writer_write_map_with_ref(_this, map TSRMLS_CC);
    }
}

ZEND_METHOD(hprose_writer, writeStdClass) {
    zval *obj = NULL;
    HPROSE_THIS(writer);
    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "o", &obj) == SUCCESS) {
        hprose_writer_write_stdclass(_this, obj TSRMLS_CC);
    }
}

ZEND_METHOD(hprose_writer, writeStdClassWithRef) {
    zval *obj = NULL;
    HPROSE_THIS(writer);
    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "o", &obj) == SUCCESS) {
        hprose_writer_write_stdclass_with_ref(_this, obj TSRMLS_CC);
    }
}

ZEND_METHOD(hprose_writer, writeObject) {
    zval *obj = NULL;
    HPROSE_THIS(writer);
    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "o", &obj) == SUCCESS) {
        hprose_writer_write_object(_this, obj TSRMLS_CC);
    }
}

ZEND_METHOD(hprose_writer, writeObjectWithRef) {
    zval *obj = NULL;
    HPROSE_THIS(writer);
    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "o", &obj) == SUCCESS) {
        hprose_writer_write_object_with_ref(_this, obj TSRMLS_CC);
    }
}

ZEND_METHOD(hprose_writer, reset) {
    HPROSE_THIS(writer);
    hprose_writer_reset(_this);
}

ZEND_BEGIN_ARG_INFO_EX(hprose_writer_void_arginfo, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(hprose_writer_construct_arginfo, 0, 0, 1)
    ZEND_ARG_OBJ_INFO(0, stream, HproseBytesIO, 0)
    ZEND_ARG_INFO(0, simple)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(hprose_writer_serialize_arginfo, 0, 0, 1)
    ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(hprose_writer_write_integer_arginfo, 0, 0, 1)
    ZEND_ARG_INFO(0, i)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(hprose_writer_write_double_arginfo, 0, 0, 1)
    ZEND_ARG_INFO(0, d)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(hprose_writer_write_infinity_arginfo, 0, 0, 0)
    ZEND_ARG_INFO(0, positive)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(hprose_writer_write_bool_arginfo, 0, 0, 1)
    ZEND_ARG_INFO(0, b)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(hprose_writer_write_utf8char_arginfo, 0, 0, 1)
    ZEND_ARG_INFO(0, ch)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(hprose_writer_write_string_arginfo, 0, 0, 1)
    ZEND_ARG_INFO(0, str)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(hprose_writer_write_bytes_arginfo, 0, 0, 1)
    ZEND_ARG_INFO(0, bytes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(hprose_writer_write_bytes_io_arginfo, 0, 0, 1)
    ZEND_ARG_OBJ_INFO(0, dt, HproseBytesIO, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(hprose_writer_write_datetime_arginfo, 0, 0, 1)
    ZEND_ARG_OBJ_INFO(0, dt, DateTime, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(hprose_writer_write_array_arginfo, 0, 0, 1)
    ZEND_ARG_ARRAY_INFO(0, arr, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(hprose_writer_write_list_arginfo, 0, 0, 1)
    ZEND_ARG_OBJ_INFO(0, list, Traversable, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(hprose_writer_write_map_arginfo, 0, 0, 1)
    ZEND_ARG_OBJ_INFO(0, map, SplObjectStorage, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(hprose_writer_write_stdclass_arginfo, 0, 0, 1)
    ZEND_ARG_OBJ_INFO(0, obj, stdClass, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(hprose_writer_write_object_arginfo, 0, 0, 1)
    ZEND_ARG_OBJ_INFO(0, obj, NULL, 0)
ZEND_END_ARG_INFO()

static zend_function_entry hprose_writer_methods[] = {
    ZEND_ME(hprose_writer, __construct, hprose_writer_construct_arginfo, ZEND_ACC_PUBLIC | ZEND_ACC_CTOR)
    ZEND_ME(hprose_writer, __destruct, hprose_writer_void_arginfo, ZEND_ACC_PUBLIC | ZEND_ACC_DTOR)
    ZEND_ME(hprose_writer, serialize, hprose_writer_serialize_arginfo, ZEND_ACC_PUBLIC)
    ZEND_ME(hprose_writer, writeInteger, hprose_writer_write_integer_arginfo, ZEND_ACC_PUBLIC)
    ZEND_MALIAS(hprose_writer, writeLong, writeInteger, hprose_writer_write_integer_arginfo, ZEND_ACC_PUBLIC)
    ZEND_ME(hprose_writer, writeDouble, hprose_writer_write_double_arginfo, ZEND_ACC_PUBLIC)
    ZEND_ME(hprose_writer, writeNaN, hprose_writer_void_arginfo, ZEND_ACC_PUBLIC)
    ZEND_ME(hprose_writer, writeInfinity, hprose_writer_write_infinity_arginfo, ZEND_ACC_PUBLIC)
    ZEND_ME(hprose_writer, writeNull, hprose_writer_void_arginfo, ZEND_ACC_PUBLIC)
    ZEND_ME(hprose_writer, writeEmpty, hprose_writer_void_arginfo, ZEND_ACC_PUBLIC)
    ZEND_ME(hprose_writer, writeBoolean, hprose_writer_write_bool_arginfo, ZEND_ACC_PUBLIC)
    ZEND_ME(hprose_writer, writeUTF8Char, hprose_writer_write_utf8char_arginfo, ZEND_ACC_PUBLIC)
    ZEND_ME(hprose_writer, writeString, hprose_writer_write_string_arginfo, ZEND_ACC_PUBLIC)
    ZEND_ME(hprose_writer, writeStringWithRef, hprose_writer_write_string_arginfo, ZEND_ACC_PUBLIC)
    ZEND_ME(hprose_writer, writeBytes, hprose_writer_write_bytes_arginfo, ZEND_ACC_PUBLIC)
    ZEND_ME(hprose_writer, writeBytesWithRef, hprose_writer_write_bytes_arginfo, ZEND_ACC_PUBLIC)
    ZEND_ME(hprose_writer, writeBytesIO, hprose_writer_write_bytes_io_arginfo, ZEND_ACC_PUBLIC)
    ZEND_ME(hprose_writer, writeBytesIOWithRef, hprose_writer_write_bytes_io_arginfo, ZEND_ACC_PUBLIC)
    ZEND_ME(hprose_writer, writeDateTime, hprose_writer_write_datetime_arginfo, ZEND_ACC_PUBLIC)
    ZEND_ME(hprose_writer, writeDateTimeWithRef, hprose_writer_write_datetime_arginfo, ZEND_ACC_PUBLIC)
    ZEND_ME(hprose_writer, writeArray, hprose_writer_write_array_arginfo, ZEND_ACC_PUBLIC)
    ZEND_ME(hprose_writer, writeAssocArray, hprose_writer_write_array_arginfo, ZEND_ACC_PUBLIC)
    ZEND_ME(hprose_writer, writeList, hprose_writer_write_list_arginfo, ZEND_ACC_PUBLIC)
    ZEND_ME(hprose_writer, writeListWithRef, hprose_writer_write_list_arginfo, ZEND_ACC_PUBLIC)
    ZEND_ME(hprose_writer, writeMap, hprose_writer_write_map_arginfo, ZEND_ACC_PUBLIC)
    ZEND_ME(hprose_writer, writeMapWithRef, hprose_writer_write_map_arginfo, ZEND_ACC_PUBLIC)
    ZEND_ME(hprose_writer, writeStdClass, hprose_writer_write_stdclass_arginfo, ZEND_ACC_PUBLIC)
    ZEND_ME(hprose_writer, writeStdClassWithRef, hprose_writer_write_stdclass_arginfo, ZEND_ACC_PUBLIC)
    ZEND_ME(hprose_writer, writeObject, hprose_writer_write_object_arginfo, ZEND_ACC_PUBLIC)
    ZEND_ME(hprose_writer, writeObjectWithRef, hprose_writer_write_object_arginfo, ZEND_ACC_PUBLIC)
    ZEND_ME(hprose_writer, reset, hprose_writer_void_arginfo, ZEND_ACC_PUBLIC)
    ZEND_FE_END
};

HPROSE_OBJECT_HANDLERS(writer)

HPROSE_OBJECT_FREE_BEGIN(writer)
    if (intern->_this) {
        hprose_writer_free(intern->_this);
        intern->_this = NULL;
    }
HPROSE_OBJECT_FREE_END

HPROSE_OBJECT_NEW_BEGIN(writer)
HPROSE_OBJECT_NEW_END(writer)

HPROSE_CLASS_ENTRY(writer)

HPROSE_STARTUP_FUNCTION(writer) {
    HPROSE_REGISTER_CLASS("Hprose", "Writer", writer);
    HPROSE_REGISTER_CLASS_HANDLERS(writer);
    return SUCCESS;
}
