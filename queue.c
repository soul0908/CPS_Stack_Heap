#include <stdio.h>

typedef int element;

typedef struct {
	element list[100]; // �迭 ����
	int pointer; // �߰��Ҷ� ���� ����Ű�� ������
	int tail_pointer; // ���������� ����Ű�� ������
} ArrayListType;

// ����Ʈ�� �ʱ�ȭ �ϴ� �Լ� �� ������ ������ ����Ŵ.
void init(ArrayListType* L)
{
	L->pointer = 0; // �⺻�� list�� 0��° �ε������� ������.
	L->tail_pointer = 0; // �����ݷ� ���� ����
}


void add(ArrayListType* L, element item) {
	L->list[L->pointer] = item;
	printf("list�� %d��°�� Push : %d\n", L->pointer, item);
	L->pointer++;
}

int make_remove(ArrayListType* L) {
	if (L->pointer = 0) { // ���� �ȿ� �ƹ��͵� ���� ����
		printf("������ ����ֽ��ϴ�.\n");
		return -1; // ���� �� ��ȯ
	}
	int ret_item = L->list[L->tail_pointer]; // ������ �� ã�ƿ���
	printf("list�� %d��°�� Pop : %d\n", L->tail_pointer, ret_item); // ��� �޽��� ����
	L->tail_pointer++; // ������ ������ ����
	return ret_item;
}

int main() {
	ArrayListType Stack; // �����Ͱ� �ƴ� ���� ������ ����
	init(&Stack); // �����Ͱ� �ƴ� ������ �ּҸ� ����
	add(&Stack, 10);
	add(&Stack, 20);
	add(&Stack, 30);
	make_remove(&Stack);
	make_remove(&Stack);
	return 0;
}
