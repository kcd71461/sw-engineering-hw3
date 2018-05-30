# sw-engineering-hw3
Environment: cmake, make, cc, c++, gdb
IDE: CLion


## 1. Overview

* functional requirement마다 Control, Boundary Class가 존재하고 각각 AbstractControl, AbstractBoundary를 상속.
* AbstractControl.h, AbstractBoundary.h 내에는 Control과 Boundary 각각 매칭되는 Boundary, Control을 반환하는 인터페이스(inherited class의 이름 규칙과 Type을 맞춰서)를 생성하는 Macro가 포함되어있다.
* 소스코드중에는 Singleton패턴을 사용하는 Class들이 존재하고 Singleton패턴 적용 코드는 매크로로 사용하여 자동 생성된다 (SingletonMacro.h)


## 2. Build CommandLine

```
$ cmake CMakeList.txt
$ make
$ ./sw_engineering_hw3
```

## 3. Boundary, Control Class 구현
### SomethingUI 클래스와 SomethingControl 클래스 만들기
#### 3.1 boundaries\SomethingUI.h
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


#### 3.2 boundaries\SomethingUI.cpp
```
#include "SomethingUI.h"
#include "../controls/SomethingControl.h"

GENERATE_DEFAULT_BOUNDARY_INTERFACE_IMPLEMENT(SomethingUI,SomethingControl)
// TODO: 필요한 Boundary 함수 구현
```

#### 3.3 controls\SomethingControl.h
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


#### 3.4 controls\SomethingControl.cpp
```
#include "SomethingControl.h"

GENERATE_DEFAULT_CONTROL_INTERFACE_IMPLEMENT(SomethingControl,SomethingUI)
GENERATE_SINGLETON_IMPLEMENT(SomethingControl)
// TODO: 필요한 Control 함수 구현
```



## 4. 현재 세션 회원 정보 가져오기
```
SessionCollection::getInstance()->getCurrentSession(); //현재 세션
SessionCollection::getInstance()->getCurrentSession()->isGuest(); //현재 세션이 Guest세션인가?
SessionCollection::getInstance()->getCurrentSession()->getMember(); //현재 로그인한 세션의 회원정보, Guest세션일 경우 NULL
```


## 5. 현재 시간 가져오기
```
std::string currentTime = Time::getCurrentTime();
```
