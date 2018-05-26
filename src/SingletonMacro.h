//
// Created by kimch on 5/26/2018.
//

#ifndef SW_ENGINEERING_HW3_SINGLETONMACRO_H
#define SW_ENGINEERING_HW3_SINGLETONMACRO_H

/**
 * singleton 구현부(.cpp) 코드 생성
 */
#define GENERATE_SINGLETON_IMPLEMENT(CLASS_NAME) CLASS_NAME *CLASS_NAME::instance = NULL;\
CLASS_NAME *CLASS_NAME::getInstance() {\
if (instance == NULL) {instance = new CLASS_NAME();}\
return instance;\
}

/*
 * singleton 선언부(.h) 코드 생성
 */
#define GENERATE_SINGLETON_DECLARE(CLASS_NAME) private:\
static CLASS_NAME *instance;\
public :\
static CLASS_NAME *getInstance();

#endif //SW_ENGINEERING_HW3_SINGLETONMACRO_H
