# MyVector 구현 과제

`std::vector<int>`를 흉내내어 `MyVector`를 구현한다.

## 개요

`std::vector`는 효율적인 동적배열이다.
본 과제에서는 `std::vector`를 흉내내어 `MyVector`를 구현한다.

## 구현해야 할 함수 목록

구현을 위해 수정할 파일은
    [`src/myvec.cpp`](../src/myvec.cpp)와 [`include/myvec.h`](../include/myvec.h)이다.
구현을 위해 아래 목록 이외의 멤버함수가 필요하면 자유롭게 정의해도 된다.

### push_back

* 선언 <br>
    `void push_back(int value)`
* 기능 <br>
    배열의 맨 뒤에 새로운 값 `value`를 추가한다. <br>
    필요한대로 메모리를 새로 할당받는다.

### pop_back

* 선언 <br>
    `void pop_back()`
* 기능 <br>
    배열의 맨 뒤 값을 제거하고 크기를 줄인다. <br>
    필요한대로 메모리를 새로 할당받는다.

### clear

* 선언 <br>
    `void clear()`
* 기능 <br>
    배열을 비운다. 즉, 빈 배열로 만든다.

### resize

* 선언 <br>
    `void resize(unsigned int n)`
* 기능 <br>
    배열의 크기를 새로 설정한다. <br>
    새로 지정한 크기가 기존 배열보다 작다면 배열을 뒤에서부터 자른다. <br>
    새로 지정한 크기가 기존 배열보다 크다면 배열 뒤에 남는만큼 0을 덧붙인다.

### size

* 선언 <br>
    `unsigned int size()`
* 기능 <br>
    배열의 크기를 반환한다.

### empty

* 선언 <br>
    `bool empty()`
* 기능 <br>
    배열이 비어있다면 `true`를 반환한다. (i.e. `size()`가 0)

### get

* 선언 <br>
    `int get(int i)`
* 기능 <br>
    배열의 `i`번째 값을 반환한다. <br>
    `i`가 배열의 범위를 벗어나는 경우 0을 반환한다.

## 채점 (총 100점)

### 채점 방법

```bash
./scripts/grade-myvec.sh
```

### 정확성 평가

\* 각 테스트는 이전 단계 테스트를 통과하지 못하면 건너뛴다.

1. `push_pop_test` (40점) <br>
    `push_back`, `pop_back`, `get` 함수가 정확하게 작동하는지 평가한다.
2. `size_test` (20점) <br>
    `size` 함수가 정확하게 작동하는지 평가한다.
3. `resize_test` (20점) <br>
    `resize` 함수가 정확하게 작동하는지 평가한다.
4. `clear_test` (10점) <br>
    `clear` 함수가 정확하게 작동하는지 평가한다.
5. `empty_test` (10점) <br>
    `empty` 함수가 정확하게 작동하는지 평가한다.
