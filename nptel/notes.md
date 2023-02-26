1. D
2. C
3. B
4. C
5. A
6. D
7. A
8. D
9. D
10. A


[gpu slides](https://www3.nd.edu/~zxu2/acms60212-40212/Lec-11-GPU.pdf)

```c
void some_func(int *a, int *b, int *c)
{
	int i;
	for (i = 0; i < 128; i++)
	{
		a[i] = b[i] * c[i];
	}
}
```
