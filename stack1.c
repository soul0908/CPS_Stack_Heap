#include <stdio.h>
#include <stdbool.h>

typedef int element;

typedef struct {
	element list[100];
	int pointer;
} ArrayListType;

// ����Ʈ�� �ʱ�ȭ�ϴ� �Լ�
void init(ArrayListType* L) {
	L->pointer = 0; // �⺻�� list�� 0��° �ε������� ������.
}

void push(ArrayListType* L, element item) {
	L->list[L->pointer] = item;
	L->pointer++;
	printf("list�� %d��°�� Push : %d\n", L->pointer, item);
}

int pop(ArrayListType* L) {
	if (L->pointer == 0) { // �ʱ�ȭ�� ���·� �ǵ��� ���� ���¿��� pop �ҷ��Ѵ� -> ���� �߻��ϴ� ��
		printf("������ ����ֽ��ϴ�.\n");
		return -1; // ���� �� ��ȯ
	}
	L->pointer--;
	int ret_item = L->list[L->pointer];
	printf("list�� %d��°�� Pop : %d\n", L->pointer + 1, ret_item);
	return ret_item;
}

int top(ArrayListType* L) {
	if (L->pointer == 0) { // �ʱ�ȭ�� ���·� �ǵ��� ���� ���¿��� pop �ҷ��Ѵ� -> ���� �߻��ϴ� ��
		printf("������ ����ֽ��ϴ�.\n");
		return -1; // ���� �� ��ȯ
	}
	int ret_item = L->list[L->pointer - 1]; // ����: �ùٸ� �ε��� ����
	printf("list�� %d��°�� Top  : %d\n", L->pointer, ret_item);
	return ret_item;
}

bool isempty(ArrayListType* L) {
	if (L->pointer == 0) { // �ʱ�ȭ�� ���·� �ǵ��� ���� ���¿��� pop �ҷ��Ѵ� -> ���� �߻��ϴ� ��
		printf("������ ����ֽ��ϴ�.\n");
		return true;
	}
	else {
		return false;
	}
}

int main() {
	ArrayListType Stack; // �����Ͱ� �ƴ� ���� ������ ����
	init(&Stack); // �����Ͱ� �ƴ� ������ �ּҸ� ����
	push(&Stack, 10);
	push(&Stack, 20);
	push(&Stack, 30);
	pop(&Stack);
	pop(&Stack);
	top(&Stack);
	isempty(&Stack);
	return 0;
}
