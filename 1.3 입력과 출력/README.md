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

---

### 출력

> cout와 printf가 존재

#### cout

> cout << 출력할 것 << "\n"을 일반적으로 사용
>
> 한칸 띄어쓰기를 원하면 cout << 출력할 것 << " "
>
> << 이어서 입력할 문자열이나 문자도 입력 가

```c++
#include <bits/stdc++.h>
using namespace std;
string a = "도랄팍 화이팅! ";
string b = "윤하 노래 너무 좋다...";
int main() {
    cout << a << "\n";
    cout << a << " " << "" << b << "\n";
    return 0;
}
/*
도랄팍 화이팅! 
도랄팍 화이팅!  윤하 노래 너무 좋다...
```

**cout의 실수 타입 출력**

> cout는 기본적으로 실수를 출력하면 일부분만 출력
>
> 실수를 출력하고자 할땐 `cout.precision(자리수 + 1);`을 걸어 사용

```c++
#include <bits/stdc++.h>
using namespace std;
double a = 1.23456789;
int main() {
    cout << a << "\n";	// 1.23457
    cout.presion(7);
    cout << a << "\n";	// 1.234568
    return 0;
}
```

---

#### printf

> printf는 형식을 지정해서 출력할 때 좋다.
>
> 다음 코드처럼 형식을 정한 후 다음 매개변수로 변수를 넣으면 형식에 맞춰서 출력된다.
>
> `int printf ( const char * format, ... );

```
#include <bits/stdc++.h>
using namespace std;
int a = 1, b = 2;
int main() {
	printf("홍철 %d : 지수 %d \n", a, b);
	return 0;
}
```

- 자리수 지정해서 출력

```c++
#include <bits/stdc++.h>
using namespace std;
double a = 1.23456789;
int b = 12;
int c = 2;
int main() {
    printf("%.6lf\n", a);	// 소수점 6자리
    printf("%02d\n", b);	// 정수 2자리
    printf("%02d\n", c);	// 정수 2자리
    return 0;
}
```

- 형식을 지정해서 출력

```c++
#include <bits/stdc++.h>
using namespace std;
int a = 1;
char s = 'a';
string str = "어벤져스";
double b = 1.223123;

int main() {
    printf("아이엠어 아이언맨 : %d\n", a);
    printf("아이엠어 아이언맨 : %c\n", s);
    printf("아이엠어 아이언맨 : %s\n", str.c_str());
    printf("아이엠어 아이언맨 : %lf\n",b);
    return 0;
}
```

※ string str을 출력할 때는 c_str() 함수를 사용해서 출력하는 것 주의!!

- printf를 기반으로 문자열을 출력하려면 string을 문자열에 대한 포인터(char *) 타입으로 바꿔주어야 한다.
- 그래서 보통 문자열을 출력할 때는 간단히 cout을 사용하는 것이 좋다.