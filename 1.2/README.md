# 1.2 기본

### 예제로 이해하는 C++

```c++
#include <bits/stdc++.h> // (1)
using namespace std; // (2)
string a; // (3)
int main() { 
    cin >> a; // (4)
    cout << a << "\n"; // (5)
    return 0; // (6)
}
```

1. `#include <bits/stdc++.h>`

   - 헤더파일을 include 시킨다.
   - `bits/stdc++.h`는 **C++**의 모든 표준 라이브러리가 포함된 헤더파일
   - 이를 include라는 지시문을 통해 이 프로그램에 포함시킨다는 의미

2. std라는 네임스페이스를 사용한다.

   - 네임스페이스란
     - 많은 라이브러리를 불러서 사용하다보면 변수명 중복이 발생할 수 있는데 이를 방지하기 위해서 변수명에 범위를 걸어놓는 것을 의미
   - cin이나 cout 등을 사용할 때 원래는 std라는 네임스페이스를 통해 std::cin 이렇게 호출을 해야하는데 std를 기본으로 설정해서 cin, cout으로 호출 가능

3. 문자열 변수 a 선언

   - `<타입> <변수명>` 선언
   - String a = "상욱" 일 때 a를 `lvalue`, 상욱을 `rvalue`라고 한다.
   - `lvalue`는 왼쪽에 정의되며 추후에 다시 사용될 수 있는 변수
   - `rvalue`는 오른쪽에 정의되며 한번쓰고 다시 사용되지 않을 변수

4. 변수 a를 입력 받는다.

   - 대표적으로 입력함수는 cin, scanf가 존재

5. 변수 a를 출력한다.

   - 대표적으로 출력함수는 cout와 printf가 존재

6. **main함수를 종료시키는 return 0**

   - 프로세스를 정상적으로 마무리한다는 의미
   - C++로 만든 프로그램은 실행시  main() 함수 하나를 찾고 그곳부터 실행을 시작

   - 즉, cpp 파일당 반드시 하나의 main 함수를 만들어야 한다.

---

### typedef

> typedef를 통해 타입의 이름을 새로이 별칭으로 정의하고 실제 타입이름 대신 별칭으로 사용 가능
>
> 이를 통해 C++에서 이미 정의된 타입 또는 사용자가 정의한 타입 보다 더 짧거나 의미있는 이름 짓기 가능
>
> `typedef <타입> <별칭>`

```c++
#include <bits/stdc++.h>
using namespace std;
typedef int i;
int main() {
    i a = 1;
    cout << a << '\n';
    return 0;
}
```

---

### define

> define을 통해 상수, 매크로를 정의
>
> `#define <이름> <값>`

```c++
#include <bits/stdc++.h>
using namespace std;
#define PI 3.14159
#define loop(x, n) for(int x = 0; x < n; x++)

int main() {
    cout << PI << '\n';
    int sum = 0;
    loop(x, 10) {
        sum += i;
    }
    cout << sum << '\n';
    return 0;
}
```

---

### STL

> C++은 STL을 제공하며 이는 자료구조, 함수 등을 제공하는 라이브러리를 뜻한다.
>
> 알고리즘, 컨테이너, 이터레이터, 펑터 이렇게 4가지를 제공한다.
>
> C++로 vector라는 자료구조를 쓴다던가 sort()함수를 쓸 수 있는 것은 다 STL 덕분이다.

**알고리즘**

- 정렬, 탐색 등에 관함 함수로 이루어져 있다.
- sort()가 대표적이다.

**컨테이너**

- C++에서 제공하는 자료구조를 의미
- 시퀀스 컨테이너
  - 데이터를 단순히 저장해 놓는 자료구조
  - array, vector, deque, forward_list, list 등
- 연관 컨테이너
  - 자료가 저장됨에 따라 자동정렬되는 자료구조
  - 중복키가 가능한 것은 이름에 multi가 붙는다.
  - set, map, multiset, multimap 등
- 정렬되지 않은 연관 컨테이너
  - 자료가 저장됨에 따라 자동정렬이 되지 않는 자료구조
  - unordered_set, unordered_map, unordered_multiset, unordered_multimap 등
- 컨테이너 어탭터
  - 시퀀스 컨테이너를 이용해 만든 자료구조
  - stack, queue는 deque로 만들어져 있으며
  - priority_queue는 vector을 이용해 힙 자료구조로 만든다.

**이터레이터**

- 추후에 설명

**펑터**

- 펑터란 함수 호출 연산자를 오버로드하는 클래스의 인스턴스
