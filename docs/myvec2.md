# MyVector 개선 과제

`MyVector`의 메모리 사용 방식을 개선한다.

## 개요

과제 1에서 구현한 `MyVector`는 배열의 크기가 변할 때마다 메모리를 새로 할당받는다.
그러나, `realloc`등을 통한 메모리 재할당은 속도가 느리고,
    잦은 메모리 재할당은 비효율적이다.
`std::vector`는 `size`와 `capacity`를 따로 생각하여 위 문제를 해소한다.
`size`는 배열의 크기이고, `capacity`는 실제로 할당받은 메모리 크기이다.
`size`가 `capacity`보다 큰 값이 요구되는 순간 (eg. `push_back`),
    `std::vector`는 `capacity`를 넉넉하게 두 배로 늘린다.
또한, `size`가 `capacity`의 절반보다 작아지는 순간,
    `std::vector`는 `capacity`를 그제서야 반으로 줄인다.
이런 방법을 통해 `size`가 자주 변해도 `capacity`,
    즉 실제 메모리 할당량은 느리게 변화시킴으로써 성능을 끌어올린다.

## 구현 내용

과제 1에서 작성한 [`src/myvec.cpp`](src/myvec.cpp)와 [`src/myvec.h`](src/myvec.h)를 수정한다.

### push_back

`size`

### pop_back

* 선언 <br>
    `void pop_back()`
* 기능 <br>
    배열의 맨 뒤 값을 제거하고 크기를 줄인다. <br>
    필요한대로 메모리를 새로 할당받는다.

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
    `i`가 배열의 범위를 벗어나는 경우는 고려하지 않는다.

## 채점 (총 150점)

### 채점 방법

```bash
./scripts/grade-myvec2.sh
```

### 정확성 평가 (100점)

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
