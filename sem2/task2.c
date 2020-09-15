// undefined behavior

char* get_some_pointer() {
	char* P;
	// Smth here..
	return P;
}

int main() {
	char* P = get_some_pointer();

	//int dead = *P;
	//if (P == 0)
	//	return;
	*P = 4;
}
