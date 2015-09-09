
void
showS16 (struct cosElemental *e)
{
	int i = 0;
	while (e)
	{
		printf ("sicle %d\n", i++);
		output (e->element);
		e = e->next;
	}
}
