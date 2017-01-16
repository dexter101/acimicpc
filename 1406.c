#include <stdio.h>
#include <string.h>

char stack[600001];
char stack2[600001];

int top = -1;
int top2 = -1;
int N;

void push(char element)
{
	stack[++top] = element;
}

void push2(char element)
{
	stack2[++top2] = element;
}

char pop()
{
	return stack[top--];
}

char pop2()
{
	return stack2[top2--];
}

int main()
{
	char temp[100001];
	int i;
	char op;
	char operand;

	freopen("input.txt", "r", stdin);

	scanf("%s", temp);
	for (i = 0; i < strlen(temp); i++)
		push(temp[i]);
	scanf("%d\n", &N);

	while (N--)
	{
		scanf("%c", &op);
		if (op == 'P')
		{
			scanf(" %c\n", &operand);
			push(operand);
		}
		else if (op == 'L')
		{
			scanf("\n");
			push2(pop());
		}
		else if (op == 'D')
		{
			scanf("\n");
			push(pop2());
		}
		else if (op = 'B')
		{
			scanf("\n");
			if (top != -1)
				pop();
		}
	}
	
	for (i = 0; i <= top; i++)
		printf("%c", stack[i]);
	for (i = 0; i <= top2; i++)
		printf("%c", stack2[i]);
	printf("\n");
}