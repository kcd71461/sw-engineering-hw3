# sw-engineering-hw3
environment: Ubuntu (WSL), CLion, cmake(3.5.1), make, cc, c++, gdb


## 1. Boundary, Control Class 구현
### SomethingUI 클래스와 SomethingControl 클래스 만들기
#### 1.1 boundaries\SomethingUI.h
```
#ifndef SW_ENGINEERING_HW3_SOMETHINGUI_H
#define SW_ENGINEERING_HW3_SOMETHINGUI_H


#include "AbstractBoundary.h"

class SomethingControl;

class SomethingUI : public AbstractBoundary {
GENERATE_DEFAULT_BOUNDARY_INTERFACE_DECLARE(SomethingControl)

public:
  // TODO: 필요한 Boundary 함수 선언
};

#endif //SW_ENGINEERING_HW3_SOMETHINGUI_H
```


#### 1.2 boundaries\SomethingUI.cpp
```
#include "SomethingUI.h"
#include "../controls/SomethingControl.h"

GENERATE_DEFAULT_BOUNDARY_INTERFACE_IMPLEMENT(SomethingUI,SomethingControl)
// TODO: 필요한 Boundary 함수 구현
```

#### 1.3 controls\SomethingControl.h
```
#ifndef SW_ENGINEERING_HW3_SOMETHINGCONTROL_H
#define SW_ENGINEERING_HW3_SOMETHINGCONTROL_H

#include "../SingletonMacro.h"
#include "../boundaries/SomethingUI.h"
#include "AbstractControl.h"
class SomethingUI;

class SomethingControl : public AbstractControl {
    GENERATE_SINGLETON_DECLARE(SomethingControl)
    GENERATE_DEFAULT_CONTROL_INTERFACE_DECLARE(SomethingControl, SomethingUI)
    
public:
  // TODO: 필요한 Control 함수 선언
};

#endif //SW_ENGINEERING_HW3_SOMETHINGCONTROL_H
```


#### 1.4 controls\SomethingControl.cpp
```
#include "SomethingControl.h"

GENERATE_DEFAULT_CONTROL_INTERFACE_IMPLEMENT(SomethingControl,SomethingUI)
GENERATE_SINGLETON_IMPLEMENT(SomethingControl)
// TODO: 필요한 Control 함수 구현
```



## 2. 현재 세션 회원 정보 가져오기
```
SessionCollection::getInstance()->getCurrentSession(); //현재 세션
SessionCollection::getInstance()->getCurrentSession()->isGuest(); //현재 세션이 Guest세션인가?
SessionCollection::getInstance()->getCurrentSession()->getMember(); //현재 로그인한 세션의 회원정보, Guest세션일 경우 NULL
```
