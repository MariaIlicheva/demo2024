#include <cmath>
#include <iostream>
#include <string>
#include <cctype>
#include <vector>
int divisors(long long n) {
	if (n==1) return 1;
    int count = 2;
    for (int i=2; i<=int(sqrt(n)); ++i) {
    	if (n%i==0) {
    		count += 1;
    		count += (i*i==n)? 0:1; 
    	}
    }
    return count;
}

int growingPlant(int upSpeed, int downSpeed, int desiredHeight) {
	int height = 0;
	int days = 0;
	int delta = upSpeed - downSpeed;
  	while (height < desiredHeight) {
  		height += upSpeed;
  		if (height >= desiredHeight) {
  			return days+1;
  		}
  		height -= downSpeed;
  		days += 1;
  		std::cout << height << std::endl;
  	}
  	return days;
}

bool consecutiveDucks(unsigned int num){
	int cur = 0;

	for (int j=1; j<=num; ++j) {
		for (int i=1; i<num; ++i) {
			if (j*j + (2*i-1)*j - 2*num ==0) return true;
		}
	}
	return false;
}

int dontGiveMeFive(int start, int end) {
    int count = 0;
    for (int i=start; i<=end;++i){
    	int f = 0;
      	int j = i;
      	while (j>0){
        	if (j%10 == 5) {
              f += 1;
          	}
        	j/=10;
      	}
      	//std::cout << f <<std::endl;
      	count += ((f>0)?1:0);
    }
    //std::cout<<"count "<<count <<std::endl;
    return end-start+1-count;
}

int digits(unsigned long long int n) {
	int dig = 0;
	if (n<10) return 1;
	while (n>0){
		dig += 1;
		n /= 10;
	}
	return dig;
}

std::string balancedNum (unsigned long long int number ) {
	std::string s = std::to_string(number);
	
	int d = s.length();
	if (d<3) return "Balanced";
	if (d==3) return (number%10==number/100)?"Balanced":"Not Balanced";
	int mid = d/2 - 1;//(d%2!=0) ? (d/2-1):(d/2);
	int sum = 0;
	std::cout<<mid<<std::endl;
	for (int i = 0; i < mid; ++i){
		int a = (int)s[i] - 48; //char to int
		int b = (int)s[d-1-i] - 48;
		sum += a-b;
		std::cout<<a<<" "<<b<<" "<<sum<<std::endl;
	}
	return (sum==0)?"Balanced":"Not Balanced";
}

unsigned long long fact(int n){
	unsigned long long result = 1;
	while (n>1){
		result *= n;
		--n;
	}
	return result;
} 

std::string strong_num (int number ) {
    int sum = 0;
    int num = number;
	while (number>0){
		int dig = number%10;
		sum += fact(dig);
		number /= 10;
	}
	std::cout<<sum<<std::endl;
	return (sum==num) ? "STRONG!!!!":"Not Strong !!"; 
}

std::string disariumNumber (int number) {
	std::string str = std::to_string(number);
	int l = str.length();
	int n = number;
	while (n > 0){
		number -= pow(n%10, l);
		l -= 1;
		n /= 10;
	}
	return (number==0) ? "Disarium !!":"Not !!";
}

std::string jumpingNumber(int number) {
	std::string str = std::to_string(number);
	if ( (std::abs((int)(str[0]-'0') - (int)(str[1] -'0')) != 1) and str.length() == 2 ) {
		return "Not!!";
	}
	for (int i=1; i<str.length() -1; ++i){ 
		if ( std::abs( (int)(str[i - 1] -'0') - (int)(str[i] - '0') ) != 1 or std::abs((int)(str[i + 1] -'0') - (int)(str[i] - '0')) != 1)
			return "Not!!";
	}

	return "Jumping!!";
}

std::string specialNumber (int number) {
	while (number>0){
		if (number % 10 > 5) return "NOT!!";
		number /= 10;
	}
	return "Special!!";
}

std::string autoMorphic (int number) {
	int len = std::to_string(number).length();
	if ((number*number)%(int)pow(10,len) == number) return "Automorphic";
	return "Not!!";
}

std::vector <int> extraPerfect ( int number ) {
	std::vector <int> nums;
	std::string s;
	for (int i=1; i<=number; ++i) {
		s = "";
		while (number>0){
			s += std::to_string(number%2);
			number /= 2;
		}
		if (s[0] == '1' and s[-1] == '1') nums.push_back(i);

	}
	std::cout<<s<<std::endl;

	return nums;
}

bool tidyNumber (int number) {
	std::string s = std::to_string(number);
	for (int i=0; i<s.length()-1; ++i) {
		if ((int)s[i] >= (int)s[i+1]) return false;
	}
	return true;
}

bool check_pal(unsigned int n) {
	std::string str_n = std::to_string(n);
	int len = str_n.length();
	for(int i = 0; i < len/2; ++i) {
		if(str_n[i] != str_n[len-i-1]) return false;
	}
	return true;
}

unsigned int nextPal(const unsigned int val) {
	unsigned int n = val;
	while (check_pal(n) != true) {
		n += 1;
	}
	return n;
}

// long long filter_string(const std::string &value) {
//     std::string num = "";

//     for (char ch : value) {
//         if (ch - '0' < 10 and ch - '0' >= 0) {
//             num += ch;
//         }
//     }
//     long long number = std::stoi( num );
//     return number;
// }

std::string DNAStrand(const std::string& dna) {
	std::string s = "";
	for (int i=0; i<(int)dna.length(); ++i) {
		if (dna[i] == 'A') s += 'T'; 
		if (dna[i] == 'T') s += 'A'; 
		if (dna[i] == 'G') s += 'C'; 
		if (dna[i] == 'C') s += 'G'; 
	}
	return s;
}

int find_short(std::string str) {
	int cnt = 1;
	int min_len = 1000000000;
	for (unsigned long i=0; i<str.length()-1; ++i) {
		if (str[i+1] == ' ') {
			std::cout<<"SDG" << std::endl;
			min_len = std::min(min_len, cnt);
			cnt = 1;
		}
		else cnt += 1;
	}
	return min_len;
}

// std::string reverse_words(std::string str) {
//     std::string s = "";
//     std::string answer = "";
//     for (char ch : str) {
//         if (ch == ' ') {
//             for (int i=s.length()-1;i>=0;  --i){
//                 answer += s[i];
//             }
//             s = "";
//             answer += ch;
//             continue;
//         }
//         s += ch;
//     }
//     for (int i=s.length()-1;i>=0;  --i){
//         answer += s[i];
//     }
//     return answer;
// }

std::string to_lower(std::string a) {
    std::string str = "";
    for (char ch : a) {
        str += tolower(ch);
    }
    return str;
}
std::string sort_str(std::string s) {
    char temp;
    for (int i=0; i<(int)s.length()-1; i++) {
        for (int j=0; j<(int)s.length()-i-1; j++) {
            if (s[j] > s[j+1]) {
                temp=s[j];
                s[j]=s[j+1];
                s[j+1]=temp;
            }
        }
    }
    return s;
}
bool isAnagram(std::string test, std::string original){

    std::string first = sort_str(to_lower(test));
    std::string second = sort_str(to_lower(original));

    //std::cout << first << " " << second ;
    return (first == second) ? true:false;
}


int main(){
    std::string a, b;
    //std::getline(std::cin, a);
    std::cin>>a>>b; 
    std::cout<< isAnagram(a, b) << std::endl;

}












