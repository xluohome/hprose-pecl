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
 * hprose_class_manager.h                                 *
 *                                                        *
 * hprose class manager for pecl header file.             *
 *                                                        *
 * LastModified: Mar 13, 2015                             *
 * Author: Ma Bingyao <andot@hprose.com>                  *
 *                                                        *
\**********************************************************/

#ifndef HPROSE_CLASS_MANAGER_H
#define	HPROSE_CLASS_MANAGER_H

#include "hprose.h"

BEGIN_EXTERN_C()

zend_class_entry *get_hprose_class_manager_ce();

HPROSE_STARTUP_FUNCTION(class_manager);
HPROSE_ACTIVATE_FUNCTION(class_manager);
HPROSE_DEACTIVATE_FUNCTION(class_manager);

void _hprose_class_manager_register(const char *name, int nlen, const char *alias, int alen TSRMLS_DC);
char * _hprose_class_manager_get_alias(const char *name, int len, int* len_ptr TSRMLS_DC);
char * _hprose_class_manager_get_class(const char *alias, int len, int* len_ptr TSRMLS_DC);

#define hprose_class_manager_register(name, nlen, alias, alen) _hprose_class_manager_register((name), (nlen), (alias), (alen) TSRMLS_CC)
#define hprose_class_manager_get_alias(name, len, len_ptr) _hprose_class_manager_get_alias((name), (len), (len_ptr) TSRMLS_CC)
#define hprose_class_manager_get_class(alias, len, len_ptr) _hprose_class_manager_get_class((alias), (len), (len_ptr) TSRMLS_CC)

END_EXTERN_C()

#endif	/* HPROSE_CLASS_MANAGER_H */
