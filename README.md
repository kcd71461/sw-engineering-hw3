# sw-engineering-hw3
environment: Ubuntu (WSL), CLion, cmake(3.5.1), make, cc, c++, gdb

## Boundary, Control Class 구현
### SomethingUI 클래스와 SomethingControl 클래스 만들기
#### boundaries\SomethingUI.h
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


#### boundaries\SomethingUI.cpp
```
#include "SomethingUI.h"

GENERATE_DEFAULT_BOUNDARY_INTERFACE_IMPLEMENT(SomethingUI,SomethingControl)
// TODO: 필요한 Boundary 함수 구현
```

#### controls\SomethingControl.h
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


#### controls\SomethingControl.cpp
```
#include "RegisterControl.h"

GENERATE_DEFAULT_CONTROL_INTERFACE_IMPLEMENT(SomethingControl,SomethingUI)
GENERATE_SINGLETON_IMPLEMENT(SomethingControl)
// TODO: 필요한 Control 함수 구현
```
