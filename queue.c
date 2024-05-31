#include <stdio.h>

typedef int element;

typedef struct {
	element list[100]; // 배열 생성
	int pointer; // 추가할때 마다 가르키는 포인터
	int tail_pointer; // 마지막단을 가르키는 포인터
} ArrayListType;

// 리스트를 초기화 하는 함수 즉 마지막 지점을 가리킴.
void init(ArrayListType* L)
{
	L->pointer = 0; // 기본은 list의 0번째 인덱스에서 시작함.
	L->tail_pointer = 0;
}

void add(ArrayListType* L, element item) {
	L->list[L->pointer] = item;
	printf("list의 %d번째에 Push : %d\n", L->pointer, item);
	L->pointer++;
}

int make_remove(ArrayListType* L) {
	if (L->pointer == 0) { // 스택 안에 아무것도 없는 상태
		printf("스택이 비어있습니다.\n");
		return -1; // 에러 값 반환
	}
	int ret_item = L->list[L->tail_pointer]; // 전진한 값 찾아오기
	printf("list의 %d번째에 Pop : %d\n", L->tail_pointer, ret_item); // 출력 메시지 수정
	L->tail_pointer++; // 포인터 앞으로 전진
	return ret_item;
}

element peek(ArrayListType* L) {
	if (L->pointer == 0) {
		printf("스택이 비어있습니다.\n");
		return -1; // 에러 값 반환
	}
	return L->list[L->tail_pointer];
}

int isEmpty(ArrayListType* L) {
	return L->pointer == L->tail_pointer;
}

int main() {
	ArrayListType Stack; // 포인터가 아닌 실제 변수로 선언
	init(&Stack); // 포인터가 아닌 변수의 주소를 전달
	add(&Stack, 10);
	add(&Stack, 20);
	add(&Stack, 30);
	
	return 0;
}
