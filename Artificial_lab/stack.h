struct stack {
	int *buf;
	int count;
	int size;
};

void stack_push(struct stack *self, int data)
{
	if (self->count == self->size)
	{
		self->size = self->size + 20;
		self->buf = realloc(self->buf, sizeof(int) * self->size);
	}
	self->buf[self->count++] = data;
}

bool stack_empty(struct stack* self)
{
	return self->count == -1;
}

int stack_pop(struct stack* self)
{
	return self->buf[self->count--];
}

int stack_peek(struct stack* self)
{
	return self->buf[self->count-1];
}
