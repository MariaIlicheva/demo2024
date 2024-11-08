#include <iostream>
#include <string>
#include <vector>

std::string switch_case(char str[]) {
    int i = 0;
    while (str[i] != 0) {
        if (str[i] <= 'Z' and str[i] >= 'A' ){
            str[i] = str[i] + 'a' - 'A';
        }
        else if (str[i] <= 'z' and str[i] >= 'a' ) {
            str[i] = str[i] - 'a' + 'A';
        }
        ++i;
    }
    return str;
}

std::string reverse_words(std::string str) {
    std::string s = "";
    std::string answer = "";
    for (char ch : str) {
        if (ch == ' ') {
            for (int i = s.length() - 1; i >= 0; --i){
                answer += s[i];
            }
            s = "";
            answer += ch;
            continue;
        }
        s += ch;
    }
    for (int i = s.length()-1; i>= 0; --i){
        answer += s[i];
    }
    return answer;
}

std::string change_order(std::string str) {
    std::string rev = "";
    for (int i=str.length()-1; i>=0; --i) {
        rev += str[i];
    }
    return reverse_words(rev);
}


int main(){
//	  std::string s;
//    std::getline(std::cin, s);
//    std::cout << reverse_words(s);

    char str[] = "hello world";
    std::cout << switch_case(str) << std::endl;
    std::cout << reverse_words(str)<< std::endl;
    std::cout << change_order(str)<< std::endl;

	return 0;
}

