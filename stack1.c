#include <stdio.h>
#include <stdbool.h>

typedef int element;

typedef struct {
	element list[100];
	int pointer;
} ArrayListType;

// 리스트를 초기화하는 함수
void init(ArrayListType* L) {
	L->pointer = 0; // 기본은 list의 0번째 인덱스에서 시작함.
}

void push(ArrayListType* L, element item) {
	L->list[L->pointer] = item;
	L->pointer++;
	printf("list의 %d번째에 Push : %d\n", L->pointer, item);
}

int pop(ArrayListType* L) {
	if (L->pointer == 0) { // 초기화한 상태로 건들지 않은 상태에서 pop 할려한다 -> 오류 발생하는 거
		printf("스택이 비어있습니다.\n");
		return -1; // 에러 값 반환
	}
	L->pointer--;
	int ret_item = L->list[L->pointer];
	printf("list의 %d번째에 Pop : %d\n", L->pointer + 1, ret_item);
	return ret_item;
}

int top(ArrayListType* L) {
	if (L->pointer == 0) { // 초기화한 상태로 건들지 않은 상태에서 pop 할려한다 -> 오류 발생하는 거
		printf("스택이 비어있습니다.\n");
		return -1; // 에러 값 반환
	}
	int ret_item = L->list[L->pointer - 1]; // 수정: 올바른 인덱스 참조
	printf("list의 %d번째에 Top  : %d\n", L->pointer, ret_item);
	return ret_item;
}

bool isempty(ArrayListType* L) {
	if (L->pointer == 0) { // 초기화한 상태로 건들지 않은 상태에서 pop 할려한다 -> 오류 발생하는 거
		printf("스택이 비어있습니다.\n");
		return true;
	}
	else {
		return false;
	}
}

int main() {
	ArrayListType Stack; // 포인터가 아닌 실제 변수로 선언
	init(&Stack); // 포인터가 아닌 변수의 주소를 전달
	push(&Stack, 10);
	push(&Stack, 20);
	push(&Stack, 30);
	pop(&Stack);
	pop(&Stack);
	top(&Stack);
	isempty(&Stack);
	return 0;
}
