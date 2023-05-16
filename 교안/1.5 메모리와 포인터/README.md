# 1.5 메모리와 포인터

### 메모리

> - 메모리는 1byte 크기의 메모리 셀로 이루어져 있다.
> - 메모리 셀은 각각의  16진수로 이루어진 고유한 주소를 갖는다.

```c++
int i;
```

- 메모리에서 4바이트의 정수타입인 int타입의 변수를 저장하기 위해 4바이트의 메모리 영역을 예약한다.
- 이렇게 예약한 메모리 영역인 주소가 가리키는 영역에 int i라는 변수가 들어가게 된다.

```c++
#include <bits/stdc++.h>
using namespace std;
int i;
int main() {
    cout << &i << '\n';
    return 0
}
// 0x4a7030
```

- OS, 실행시간 등에 따라 주소할당이 달라진다.

```c++
#include <bits/stdc++.h>
using namespace std;
int i;
int main() {
	cout << &i << '\n';
	i = 0;
	cout << &i << '\n';
	
	return 0;
}
```

- 변수에 값을 할당해도, 다른 값을 넣어도 주소는 변하지 않는다.

---

### 포인터

> 메모리관리는 언어마다 다르게 관리가 되는데 C, C++ 등은 가비지컬렉터가 없으며 대신 개발자가 직접 필요한 메모리를 예약하고 해제할 수 있으며 포인터를 지원한다.

##### 포인터의 개념

- 변수의 메모리 주소를 담는 타입이 포인터
- 메모리 동적할당, 데이터를 매개변수로 사용, 클래스 및 구조체를 연결할 때 사용

```c++
#include <bits/stdc++.h>
using namespace std;
int i;
string s = "kundol";
int main() {
    i = 0;
    int * a = & i;
    cout << a << '\n';
    string * b = &s;
    cout << b << '\n';
    return 0;
}
```

- `int * a` 에 `&i`라는 `i`의 주소를 담는 포인터를 정의한다.
- `<타입> *` 형태로 포인터를 정의한다.
- `*`라는 별표는 에스터리스크(asterist operator)라고도 불린다.

##### 포인터의 크기

- OS가 32bit라면 4바이트, 64bit라면 8바이트로 고정되어있다.
- 어떠한 타입이든(string, char, int 등) 상관없이 무조건 4바이트 아니면 8바이트로 고정도니다.



### 역참조 연산자

> C++에서 `*` 기호는 사용하는 위치에 의해 다양한 용도로 사용된다.
>
> 이항 연산자로 사용하면 곱셈 연산으로, 포인터 타입의 선언, 역참조로 메모리를 기반으로 변수의 값에 접근할 때도 사용한다.

```c++
#include <bits/stdc++.h>
using namespace std;

int main() {
    string a = "abcda";
    string * b = &a;
    cout << b << "\n";
    cout << *b << "\n";
    return 0;
}
/*
0x6ffdf0
abcda
*/
```



### array to pointer decay

> 배열의 이름을 주소값으로 쓸 수 있는 것을 의미
>
> 정확히는 배열이 포인터로 부식되는 현상을 말한다.
>
> 이는 배열의 이름을 `T *` 라는 포인터에 할당하면서 T[N]이란 배열의 크기 정보 N이 없어지고 첫번째 요소의 주소가 바인딩 되는 현상을 의미한다.

```c++
#include <bits/stdc++.h>
using namespace std;
int a[3] = {1, 2, 3};
int main() {
    int * c = a;
    cout << c << "\n";
    cout << &a[0] << "\n";
    cout << c + 1 << "\n";
    cout << &a[1] << "\n";
    return 0;
}
```

- 이를 통해 배열의 이름은 배열의 첫번째 주소로써 쓸 수 있다.
- vector는 사용이 불가능하다.



### 프로세스 메모리 구조와 정적할당과 동적할당

> 운영체제는 프로레스에 적절한 메모리를 할당하는데 다음 구조를  기반으로 할당한다.
>
> 위에서부터 스택, 힙, 데이터 영역, 코드영역으로 나눠진다.
>
> 스택은 위 주소부터 할당되고 힙은 아래 주소부터 할당된다.

- 스택 : 지역변수, 매개변수, 함수가 저장되고 컴파일 시에 크기가 결정된다. 그러나 함수가 함수를 호출 하는 등에 따라 런타임시에도 크기가 변경된다. [동적인 특징]
- 힙 : 힙은 동적 할당할 때 사용되며 런타임 시 크기가 결정된다. [동적인 특징]
- 데이터 영역 : BSS 영역과 Data 영역으로 나뉘고 정적할당에 관한 부분을 담당합니다. [정적인 특징]
- 코드영역 : 소스코드 들어감 [정적인 특징]

##### 정적할당

> 컴파일 단계에서 메모리를 할당하는 것을 말한다.
>
> BSS segment와 Data segment, code / text segment로 나뉘어서 저장된다.

- BSS segment는 전역변수, static, const로 선언되어있는 변수 중 0으로 초기화 또는 초기화가 어떠한 값으로도 되어 있지 않은 변수들이 이 메모리 영역에 할당된다.

```c++
#include <bits/stdc++.h>
using namespace std;
int a;
int b = 0;
const int c = 0;
int main() {
    static int d;
    static int e = 0;
    return 0;
}
```

- Data segment은 전역변수, static, const로 선언되어있는 변수 중 0이 아닌 값으로 초기화된 변수가 이 메모리 영역에 할당된다.

```c++
#include <bits/stdc++.h>
using namespace std;
int a = 1;
const int b = 2;
int main() {
    static int c = 3;
    return 0;
}
```

##### 동적할당

- stack은 지역변수, 매개변수, 실행되는 함수에 의해 늘어나거나 줄어드는 메모리 영역이다.
  - 함수가 호출될 때마다 호출될 때의 환경 등 특정 정보가 계속해서 저장
  - 재귀함수가 호출 되었을 때 새로운 스택 프레임이 매번 사용
  - 재귀함수 내의 지역변수로 선언하게 되면 해당 변수는 독립적으로 작용하며 다른 함수에 있는 변수에 영향을 끼치지 않는다.
- Heap은 동적으로 할당되는 변수들을 담는다.
  - malloc(), free() 함수를 통해 관리할 수 있으며 동적으로 관리되는 자료구조의 경우 Heap영역을 사용합니다.