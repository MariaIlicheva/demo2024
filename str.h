
#include <iostream>
struct str {
public:
	int len;
	char* ptr;

	str();
	str(int x);
	str(const char* text);
	str(const str& text);

	~str();

	str operator=(const char* text);
	str& operator=(const str& text);

	str operator+(const char* text) const;
	str operator+(const str& text) const;

	void operator+=(const char* text);
	void operator+=(char text);
	void operator+=(const str& text);
	void operator+=(int x);
	char& operator[](int);

	void space(int x);
	void out() const;

private:
	void str_set(const char* text);
	void str_add(const char* text);
	void str_add(char text);


	str static char_to_i(int x);
	str str_copy(const char* text);
};


int strlength(const char* text) {
	if (text == nullptr) {
		return 0;
	}

	int i = 0;
	while (text[i] != '\0') {
		i++;
	}
	return i;
}

str::str() {
	len = 0;
	ptr = nullptr;
}

str::str(int x) {
	len = x;
	ptr = new char[x + 1];
	ptr[len] = '\0';
}

str::str(const char* text) {
	str_set(text);
}

str::str(const str& text) {
	str_set(text.ptr);
}

str str::operator=(const char* text) {
	delete[] ptr;
	len = 0;
	str_set(text);
	return *this;
}

str& str::operator=(const str& text) {
	delete[] ptr;
	len = 0;
	if (this != &text) {
		str_set(text.ptr);
	}
	return *this;
}

str str::operator+(const char* text) const {
	str new_str;
	new_str.str_set(ptr);
	new_str.str_add(text);
	return new_str;
}

str str::operator+(const str& text) const {
	str new_str;
	new_str.str_set(ptr);
	new_str.str_add(text.ptr);
	return new_str;
}

void str::operator+=(const char* text) {
	str_add(text);
}

void str::operator+=(const char text) {
	str_add(text);
}

void str::operator+=(const str& text) {
	str_add(text.ptr);
}

void str::operator+=(const int x) {
	str_add(char_to_i(x).ptr);
}
char& str::operator[](int n) {
	if (n > len - 1) {
		return ptr[n %len -1];
	}
	 return ptr[n];
}


str::~str() {
	delete[] ptr;

}

void str::space(int x) {
	for (int i = len; i < x; i++) {
		str_add(' ');
	}
}

void str::out() const {

	if (len == 0)
	{
		return;
	}
	for (int i = 0; i < len; i++) {
		std::cout << ptr[i];
	}
}

str str::char_to_i(int x) {

	int i = 1;
	int len = 1;

	while (i * 10 <= x) {
		i *= 10;
		len += 1;
	}

	str res(len);

	for (int j = 0; i != 0; j++) {
		res.ptr[j] = (char)(x / i + 48);

		x %= i;
		i /= 10;
	}
	return res;
}

void str::str_set(const char* text) {

	len = strlength(text);

	ptr = new char[len + 1];

	for (int i = 0; i < len; i++) {
		ptr[i] = text[i];
	}
	ptr[len] = '\0';
}

str str::str_copy(const char* text) {

	len = strlength(text);
	str new_str(len);

	for (int i = 0; i < len; i++) {
		new_str.ptr[i] = text[i];
	}
	new_str.ptr[len] = '\0';
	return new_str;
}

void str::str_add(const char* text) {
	int new_len = len + strlength(text);
	char* new_ptr = new char[new_len + 1];
	for (int i = 0; i < len; i++) {
		new_ptr[i] = ptr[i];
	}
	for (int i = 0; i < strlength(text); i++) {
		new_ptr[len + i] = text[i];
	}
	new_ptr[new_len] = '\0';
	delete[] ptr;
	len = new_len;
	ptr = new_ptr;
}

void str::str_add(const char text) {
	int new_len = len + 1;
	char* new_ptr = new char[new_len + 1];
	for (int i = 0; i < len; i++) {
		new_ptr[i] = ptr[i];
	}
	new_ptr[new_len - 1] = text;
	new_ptr[new_len] = '\0';
	delete[] ptr;
	len = new_len;
	ptr = new_ptr;
}