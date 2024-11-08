#include <iostream>
#include <cmath>
#include <vector>
#include <cctype>
#include <unordered_map>
#include <map>
int digital_root(int n) {
    int sum = 0;
    while (n > 0) {
        sum += (n%10);
        n/=10;
    }
    return ((sum>=10) ? digital_root(sum):sum);
}

bool narcissistic(int value ) {
    int len = std::to_string(value).length();
    int n = value;
    std::cout<<len;
    int sum = 0;
    while (value > 0) {
        sum += pow(value%10, len);
        value /= 10;
    }
    std::cout << sum;
    return (sum==n) ? true:false;
}

int persistence(long long n){
    int mult = 100;
    int c = 0;
    while (mult >= 10) {
        int m = 1;
        while (n > 0) {
            m *= (n % 10);
            n /= 10;
        }
        mult = m;
        ++c;
        n = m;
    }
    return c;
}

static long findMissing(std::vector<long> list){
    sort(list.begin(), list.end());
    long d = (list.back() - list.front())/list.size();

    for (int i = 1; i < (int)list.size(); ++i) {
        if (list[i] - list[i-1] != d) {
            return list[i]-d;
        }
    }
}

std::string createPhoneNumber(const int arr [10]){
    std::string phone = "(xxx) xxx-xxxx";
    int ind = 1;
    for (int i = 0; i<10; ++i) {
        phone.replace(ind, 1, std::to_string(arr[i]));
        ind = phone.find('x');
    }
    return phone;
}

std::string to_lower(std::string a) {
    std::string str = "";
    for (char ch : a) {
        str += tolower(ch);
    }
    return str;
}
std::string duplicate_encoder(const std::string& word){
    std::string res = "";
    std::string s = to_lower(word);
    for (int i =0; i<s.length(); ++i) {
        int f = 1;
        for (int j =0; j<s.length(); ++j) {
            if (s[i] == s[j] and i!=j) {
                f *= 0;
            }
        }

        res += (f==0) ? ")":"(";
    }
    return res;
}
std::string duplicate_encoder_version2(std::string w) {
    std::string r;
    int ca[256] = {0};
    for (auto c : w)
        ca[tolower(c)]++;
    for (auto c : w)
        r += ca[tolower(c)] > 1 ? ')' : '(';
    return r;
}
std::string duplicate_encoder_version3(const std::string &word) {
    std::map<char, int> counter;
    std::string s{""};
    for (char c : word) {
        counter[std::tolower(c)] += 1;
    }

    for (char c : word) {
        s += counter[std::tolower(c)] > 1 ? ")" : "(";
    }
    return s;
}

int countSmileys(std::vector<std::string> arr) {
    int ans = 0;
    for (std::string a : arr) {
        if (a.length() == 2){
            if ((a[0] == ':' or a[0] == ';') and (a[1] == ')' or a[1] == 'D')) {
                ans += 1;
            }
        }
        if (a.length() == 3){
            if ((a[0] == ':' or a[0] == ';') and (a[1] == '-' or a[1] == '~') and (a[2] == ')' or a[2] == 'D')) {
                ans += 1;
            }
        }
    }
    return ans;
}

int find_even_index(const std::vector <int> numbers) {
    int ind;
    int left = numbers.front(), right = 0;
    for (int i = 1; i<numbers.size() ; ++i){
        right += numbers[i];
    }
    if (right == 0) return 0;
    right = right - numbers[1];
    if (left == right) return 1;
    for (ind = 2; ind < numbers.size(); ++ind) {
        if (left + numbers[ind-1] == right - numbers[ind]) {
            return ind;
        }
        left += numbers[ind-1];
        right -= numbers[ind];
    }
    return -1;
}

std::string likes(const std::vector<std::string> &names) {
    if (names.size() == 0) return "no one likes this";
    if (names.size() == 1) return names[0] + " likes this";
    if (names.size() == 2) return names[0]+ " and " + names[1] + " like this";
    if (names.size() == 3) return names[0] + ", " + names[1] + " and " + names[2] + " like this";
    return names[0] + ", " + names[1] + " and " + std::to_string(names.size()- 2) + " others like this";
}

std::vector<int> foldArray(std::vector<int> arr, int runs) {
    if (runs <= 0) return arr;
    int sz = arr.size();
    std::vector <int> res;
    for (int i=0; i<sz/2; ++i) {
        res.push_back(arr[i] + arr[sz - i - i]);
    }
    if (sz%2 ==0) {
        return foldArray(res, runs-1);
    }
    res.push_back(arr[sz/2+1]);
    return foldArray(res, runs-1);
}

char findMissingLetter(const std::vector<char>& chars) {
    for (int i=1; i<chars.size(); ++i) {
        if ((int)chars[i] != (int)chars[i-1]+1) {
            char ch = (int)chars[i-1]+1;
            return ch;
        }
    }
}

std::string deleteSpaces(std::string s){
    std::string res = "";
    bool f = false;
    for (int i=0; i<s.length(); ++i) {
        if (s[i] == ' ' and f == true) res += s[i];
        if (s[i] != ' ') {
            f = true;
            res += s[i];
        }
    }
    s = "";
    f = false;
    for (int i=res.length()-1; i >= 0; --i) {
        if (res[i] == ' ' and f == true) s += res[i];
        if (res[i] != ' ') {
            f = true;
            s += res[i];
        }
    }
    reverse(s.begin(), s.end());
    return s;
}
std::string decodeMorse(const std::string& morse) {
    std::vector <std::pair<char,std::string> > alp = {
            {'A', ".-"},
            {'B', "-..."},
            {'C', "-.-."},
            {'D', "-.."},
            {'E', "."},
            {'F', "..-."},
            {'G', "--."},
            {'H', "...."},
            {'I', ".."},
            {'J', ".---"},
            {'K', "-.-"},
            {'L', ".-.."},
            {'M', "--"},
            {'N', "-."},
            {'O', "---"},
            {'P', ".--."},
            {'Q', "--.-"},
            {'R', ".-."},
            {'S', "..."},
            {'T', "-"},
            {'U', "..-"},
            {'V', "...-"},
            {'W', ".--"},
            {'X', "-..-"},
            {'Y', "-.--"},
            {'Z', "--.."},
            {'1', ".----"},
            {'2', "..---"},
            {'3', "...--"},
            {'4', "....-"},
            {'5', "....."},
            {'6', "-...."},
            {'7', "--..."},
            {'8', "---.."},
            {'9', "----."},
            {'0', "-----"},
    };
    std::string m = deleteSpaces(morse);
    std::string result = "";
    std::string s = "";
    int i = 0;
    while (i <= m.length()) {
        if (m[i] != ' ') {
            s += m[i];
        }
        if (m[i] == ' ' or (i == m.length()-1)) {
            if (s == "...---...") result += "SOS";
            if (s == "-.-.--") result += "!";
            if (s == ".-.-.-") result += ".";
            for (int a = 0; a < alp.size(); ++a) {
                if (alp[a].second == s) result += alp[a].first;
            }
            s = "";
            if (m[i+1] == ' ' and m[i+1] == ' ')  {
                result += " ";
                i += 1;
            }
        }
        ++i;
    }
    return result;

}

bool isCoprimeWith10(int n) {
    return (n % 2 != 0) and (n % 5 != 0);
}
int cycle(int n) {
    if (!isCoprimeWith10(n)) {
        return -1;
    }
    std::unordered_map<int, int> remainders;
    int r = 1;
    int pos = 0;

    while (true) {
        r %= n;
        if (r == 0) return 0;

        if (remainders.find(r) != remainders.end()) {
            return pos - remainders[r];
        }
        remainders[r] = pos;
        r *= 10;
        pos++;
    }
}

std::string alphabetWar(std::string s){
    std::string res = "";
    int i=0;
    if (s[0] == '*') i = 2;
    if (s[1] == '*') i = 3;
    if (i==0 and s[1] != '*') res += s[0];
    for (i; i<s.length(); ++i) {
        if (s[i+1] != '*' and s[i-1] != '*' and i !=0) res += s[i];
        if (s[i] == '*') continue;
    }
    if (res.length() == 0) return "Let's fight again!";
    int cnt = 0;
    for (char ch: res) {
        if (ch == 'w') cnt += 4;
        if (ch == 'p') cnt += 3;
        if (ch == 'b') cnt += 2;
        if (ch == 's') cnt += 1;
        if (ch == 'm') cnt -= 4;
        if (ch == 'q') cnt -= 3;
        if (ch == 'd') cnt -= 2;
        if (ch == 'z') cnt -= 1;
    }
    if (cnt == 0) return "Let's fight again!";
    return (cnt < 0) ? "Right side wins!": "Left side wins!";

}


std::string alphabet_war(const std::vector<std::string>& reinforces,
                         const std::vector<std::string>& airstrikes) {
    const int sz = reinforces[0].size();

    std::vector <int> tmp(sz,0);
    std::string res(sz, '_');

    for (int i = 0 ; i < airstrikes.size(); ++i) {
        const int sz_i = airstrikes[i].size();

        for (int j = 0 ; j < sz_i; ++j) {
            if (airstrikes[i][j] == '*' or (j != 0 and airstrikes[i][j-1] == '*') or (j+1 < sz and airstrikes[i][j+1] == '*')) {
                tmp[j] += 1;
            }
        }

        if (sz_i < sz and airstrikes[i].back() == '*') {
            tmp[sz_i ] += 1;
        }
    }

    for (int i = 0 ; i < sz ; ++i) {
        if (tmp[i] < reinforces.size()) res[i] = reinforces[tmp[i]][i];
    }
    return res;
}

int main() {
    int n;
    //std::cin>>n;
    std::cout << alphabet_war({"abcdefg",
                               "hijklmn"}, {"   *   ",
                                            "*  *   "});
    return 0;
}

