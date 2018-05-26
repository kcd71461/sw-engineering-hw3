//
// Created by kimch on 5/26/2018.
//

#ifndef SW_ENGINEERING_HW3_SINGLETONMACRO_H
#define SW_ENGINEERING_HW3_SINGLETONMACRO_H

/**
 * 반드시 static getInstance() 가 정의되어 있어야함
 */
#define GENERATE_GET_INSTANCE_IMPLEMENT(CLASS_NAME) CLASS_NAME *CLASS_NAME::getInstance() {\
if (instance == NULL) {instance = new CLASS_NAME();}\
return instance;\
}

#endif //SW_ENGINEERING_HW3_SINGLETONMACRO_H
