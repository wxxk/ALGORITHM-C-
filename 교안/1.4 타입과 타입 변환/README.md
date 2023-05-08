# 1.4 타입과 타입 변환

### 타입

> 다음 타입들은 알고리즘에 자주 나오는 타입 8개이다.
>
> `long` `double` 등 조금 더 있지만 이정도만 배워도 충분하다.
>
> `void, char, string, bool, int, long long, double, unsigned long long`

#### 1. void : 리턴하는 값이 없다.

```c++
#include <bits/stdc++.h>
using namespace std;
int res = 1;
void a() {
    ret = 2;
    cout << ret << "\n";
    return;
}
int main() {
    a();
    return 0;
}
```

- a라는 함수가 ret을 바꾸고 아무것도 리턴하지 않는다.
- 이렇게 아무것도 리턴하지 않는 함수에는 void로 선언한다.



```c++
#include <bits/stdc++.h>
using namespace std;
double a() {
    return 1.233;
}
int main() {
    double ret = a();
    cout << ret << "\n";
    return 0;
}
```

- void가 아닌 double 타입을 반환하는 함수의 정의이다.
- 다음 코드 처럼 a()라는 함수는 double 타입으로 정의 되어 있다.
- 또한 함수를 선언할 때는 항상 호출되는 위쪽 부분에 선언해야 한다.
- 타입과 인자만 선언 해 놓고 아래쪽에 함수를 정의하는 식으로 선언부와 정의부를 나눠서 함수를 설정하는 방법도 있다.

```c++
#include <bits/stdc++.h>
using namespace std;
double a();
int main() {
    double ret = a();
    cout << ret << "\n";
    return 0;
}

double a() {
    return 1.23333;
}
```

- 그러나 알고리즘은 시간 싸움이기 때문에 이렇게 두번 함수를 적게되면 시간낭비이다.

---

#### 2. char, 문자

> 작은  따옴표 `''` 이렇게 선언해야 하며 1바이트의 크기를 가진다.

```c++
#include <bits/stdc++.h>
using namespace std;
int main() {
    char a = 'a';
    cout << a << "\n";
    return 0;
}
```

- 문자 a를 선언하고 a를 출력한 예시이다.
- 이렇게 한 문자만 들어간다.



```c++
#include <bits/stdc++.h>
using namespace std;
char b(){
    char a = 'a';
    return a;
}
int main() {
    char a = b();
    cout << a << "\n";
    return 0;
}
```

- char을 리턴하는 함수의 예시이다.

---

#### 3. string, 문자열

> 앞서 배운 char을 아래의 코드처럼 char[] 배열로 선언하거나 그냥 string으로 선언해 여러개의 문자모음이자 문자배열인 문자열을 선언할 수 있다.
>
> `char s[10];` , `string a;`

```c++
#include <bits/stdc++.h>
using namespace std;
int main() {
    string a = "나는야";
    cout << a[0] << "\n";
    cout << a[0] << a[1] << a[2] << 'n';
    cout << a << "\n";
    string b = "abc";
    cout << b[0] << "\n";
    cout << b << "\n";
    return 0;
}
/*
?
나
나는야
a
abc
*/
```

- 한글로 선언한 a의 경우 a[0]을 출력했을 때 이상한 문자가 나온다.
- 문자열을 선언하고 a[0], a[1] 이렇게 접근한다는 의미는 0번재, 1번재 1바이트씩 출력한다는 것을 의미한다.
- 영어는 한 글자당 1바이트지만 한글은 한 글자당 3바이트이다.
- 그렇기 대문에 한글은 제대로 출력되지 않고, 영어는 제대로 잘 나온다.



```c++
#include <bits/stdc++.h>
using namespace std;
int main() {
    string a = "love is";
    a += " pain!";
    a.pop_back();
    cout << a << " : " << a.size() << "\n";
    cout << char(* a.begin()) << '\n';
    cout << char(* (a.end() -1)) << '\n';
    
    a.insert(0, "test ");
    cout << a << " : " << a.size() << "\n";
    
    a.erase(0, 5);
    cout << a << " : " << a.size() << "\n";
    
    auto it = a.find("love");
    if (it != string::npos){
        cout << "포함되어 있다." << '\n';
    }
    cout << it << '\n';
    cout << string::npos << '\n';
    
    cout << a.substr(5, 2) << '\n';
    
    return 0;
}
/*

```

---

##### `+-`

- 메서드는 아니며 문자열에서 문자열을 더할 때 보통 += 를 써서 문자열 또는 문자를 더한다.
- push_back()이라는 메서드가 있지만 이는 문자하나씩 밖에 더하지 못해 보통 `+=`를 사용한다.

##### `begin()`

- 문자열의 첫번째 요소를 가리키는 이터레이터를 반환한다.
- 이 이터레이터를 기반으로 `*`를 통해 해당 위치 값을 가져올 수 있다.

##### `end()`

- 문져열의 마지막 요소 그 다음을 가리키는 이터레이터를 반환한다.
- `begin()`과 `end()`는 자료구조인 vector, Array, 연결리스트, 맵 셋에서도 존재한다.

##### `size()`

- 문자열의 사이즈를 반환한다.
- O(1)의 시간복잡도를 가진다.

##### `insert(위치, 문자열)`

- 특정위치에 문자열을 삽입한다.
- O(n)의 시간복잡도를 가진다.

##### `erase(위치, 크기)`

- 특정위치에 크기만큼 문자열을 지운다.
- O(n)의 시간복잡도를 가진다.

##### `pop_back()`

- 문자열 끝을 지운다.
- O(1)의 시간복잡도를 가진다.

##### `find(문자열)`

- 특정 문자열을 찾아 위치를 반환한다.
- 만약 해당 문자열을 못 찾을 경우 string::npos를 반환한다.
- O(n)의 시간복잡도를 가진다.
- **string::npos**
  - size_t 타입의 최대값을 의미한다.

##### `substr(위치, 크기)`

- 특정 위치에서 크기만큼의 문자열을 추출한다.
- O(n)의 시간복잡도를 가진다.

##### `아스키코드와 문자열`

> 만약 숫자로 된 문자에서 ++증감연산자를 통해 1을 더해준다면??
>
> => 아스키코드에서 +1한 값이 된다.

```C++
#include <bits/stdc++.h>
using namespace std;
int main() {
    iso:sync_with_stdio(false);
    cin.tie(NULL);
    string s = "123";
    s[0]++;
    cout << s << "\n";	// 223
    return 0;
}
```

- 123에서 s[0]에 1을 더해 223이 되었는데 이는 아스키코드 49에서 1을 더한 값인 50이 가리키는 값이 2이기 때문에 123에서 223이 되는 것이다.
- 즉, 문자열에서 +하는 연산은 "아스키코드"를 기반으로 수행된다.

```C++
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    char a = 'a';
    cout << (int)a << '\n';
    
    return 0;
}
```

- 문자를 아스키코드로 확인하고 싶다면 타입 변환을 하면 된다.
- (int)'a'를 통해 문자 char을 정수 int로 변환할 수 있다.

##### `reverse()`

- string은 reverse()라는 메서드를 지원하지 않는다.
- 문자열을 거꾸로 뒤집고 싶으면 STL에서 지원하는 함수인 reverse()를 쓰면된다.

- `void reverse (BidirectionalIterator first, BidirectionalIterator last);`
- reverse() 함수는 void 타입으로 아무것도 반환하지 않는다.
- 원본 문자열을 바꾼다.

##### `split()`

> 코딩테스트에서는 문자열을 split() 하는 로직이 많이 등장한다.
>
> split()함수란 다른 프로그래밍 언어에서도 문자열을 특정 문자열을 기준으로 쪼개어서 배열화 시키는 함수라는 의미로 사용된다.
>
> C++언어에서는 STL에서 split() 함수를 지원하지 않는다.
>
> 그래서 만들어 주어야하고, 시간복잡도는 O(n)의 시간복잡도를 가진다.

```c++
#include <bits/stdc++.h>
using namespace std;

vector<string> split(string input, string delimiter) {
    vector<string> ret;	// split한 결과를 저장할 배열
    long long pos = 0;	// 구분자까지의 길이를 저장
    string token = "";	// 구분자까지의 문자열을 저장
    
	while ((pos = input.find(delimiter)) != string::npos) {
        token = input.substr(0, pos);
        ret.push_back(token);
        input.erase(0, pos + delimiter.length());
    }
    ret.push_back(input);
    
    return ret;
}

int main() {
    string s = "안녕하세요 큰돌이는 킹갓제너럴 천재입니다 정말이에요!", d = " ";
    vector<string> a = split(s, d);
    for(string b : a) cout << b << "\n";
}
/*
안녕하세요
큰돌이는
킹갓제너럴
천재입니다
정말이에요!
*/
```

**코드 분석**

```
while ((pos = input.find(delimiter)) != string::npos) {
	token = input.substr(0, pos);
	ret.push_back(token);
	input.erase(0, pos + delimiter.lenth());
}
```

- input에서 delimiter를 찾는다. (못 찾을 때까지 반복)

```c++
while ((pos = input.find(delimiter)) != string::npos)
```

- 찾았다면 해당 pos까지 해당 부분의 문자열을 추출한다.

```c++
	token = input.substr(0, pos);
```

- 추출한 문자열을 ret이란 배열에 집어 넣는다.

```c++
	ret.push_back(token)
```

- 앞에서부터 문자열을 지운다.
- pos와 delimeter의 크기까지 합쳐서 제거한다.

```c++
	input.erase(0, pos + delimiter.length());
```

