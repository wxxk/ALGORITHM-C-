# 1.3 입력과 출력

### 입력

> 대표적으로 cin과 scanf가 존재
>
> cin은 개행문자까지 입력을 받는다.
>
> scanf는 형식을 지정해서 입력을 받는다.

```c++
#include <bits/stdc++.h>
using namespace std;
int a;
int main() {
    cin >> a;
    scanf("%d", &a);
    return 0;
}
```



#### cin

> 문제에서 형식을 기반으로 입력이 주어지지 않은 경우 scanf보다는 cin을 쓰는 것이 더 좋다.
>
> cin은 개행문자(띄어쓰기, 엔터)까지 입력을 받는다.

```C++
#include <bits/stdc++.h>
using namespace std;
string a;
int main() {
    cin >> a;
    cout << a << "\n";
    return 0;
}

/*
입력
이상욱 안녕

출력
이상욱
*/
```

- "이상욱 안녕"을 입력했는데 출력에는 "이상욱"만 나타난다.
- 개행문자까지만 입력을 받는다.



```c++
#include <bits/stdc++.h>
using namespace std;
int main() {
    cin >> a >> b;
    cout << a << "\n";
    cout << b << "\n";
    return 0;
}
/*
입력
이상욱 안녕

출력
이상욱
안녕
*/
```

- 개행문자를 넣어서 2개의 문자열을 입력하면 모든 문자열이 올바르게 입력 받아진다.

---

#### scanf

> scanf는 첫번째 매개변수로 받는 형식을 지정해서 입력을 받는다.
>
> `int scanf ( const char * format, ... );

```c++
#include <bits/stdc++.h>
using namespace std;
int a;
double b;
char c;
int main() {
    scanf("%d %lf %c", &a, &b, &c);
    printf("%d\n", a);
    printf("%lf\n", b);
    printf("%c\n", c);
    return 0;
}
```

- scanf는 주로 입력형식이 까다롭거나 이를 이요해야할 때 사용하고, 보통은 cin을 쓰는게 좋다.

- scanf로 받을 수 있는 타입과 형식은 다음과 같다.

  | 형식 | 타입      |
  | ---- | --------- |
  | d    | int       |
  | c    | char      |
  | s    | string    |
  | lf   | double    |
  | ld   | long long |

###### scanf를 활용해 실수타입을 정수타입으로 받아보기

- 3.22처럼 double 타입으로 들어오는 것을 double 타입으로 받을 수 있지만 scanf를 이용해서 int타입 2개를 만들어 받을 수 있다.

```c++
#include <bits/stdc++.h>
using namespace std;
int a, b;
double c;
int main() {
    scanf("%d.%d", &a, &b);
    printf("\n%d %d\n", a, b);
    
    scanf("%lf", &c);
    printf("%lf\n", c);
    return 0;
}
```

---

#### getline

> 한줄을 한껍너에 입력받을 때 사용

```c++
#include <bits/stdc++.h>
using namespace std;
string s;
int main() {
    getline(cin, s);
    cout << s << '\n';
    return 0;
}
/*
엄준식 화이팅
엄준식 화이팅
*/
```



- cin으로 T개의 getline을 받을지를 설정하고 T개 만큼 getline의 입력이 들어오는 상황
  - 특정 문자열을 기반으로 버퍼플래시를 하고 받아야 한다.
  - cin으로 입력을 받을 때 개행 직전까지 입력을 받게 되고
  - 중간에 위치한 버퍼에 \n이 남아있게 된다.
  - 이를 없애주기 위해 getline(cin, bufferflush)를 사용

```c++
#include <bits/stdc++.h>
using namespace std;
int T;
string s;
int main() {
    cin >> T;
    string bufferflush;
    getline(cin, bufferflush);
    for (int i = 0; i < T; i ++) {
        getline(cin, s);
        cout << s << "\n";
    }
    return 0;
}
```

