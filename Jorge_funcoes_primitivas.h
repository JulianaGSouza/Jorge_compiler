#include <string.h>
#include <stdio.h>
#include <ctype.h>

/*function print(s : string)
Print s on standard output.*/
void t_print(std::string s){
    std::cout << s << std::endl;
}

/*function flush()
Flush the standard output buffer.*/
void t_flush(){
    std::cout.flush();
}

/*function getchar() : string
Read a character from standard input; return empty string on end of file.*/
std::string t_getChar(){
    char c = getchar();
    if (c == EOF){
        return "";
    } else {
        return c;
    }
}

/*function ord(s: string) : int
Give ASCII value of first character of s ; yields -1 if s is empty string.*/
int t_ord(std::string s){
    if (std::strcmp (s, "") == 0) {
        return -1;
    } else {
        return int(s[0]);
    }
}

/*function chr(i: int) : string
Single-character string from ASCII value i ; halt program if i out of range.*/
std::string t_chr(int i){
    if (isascii(i)) {
      char a = i;
      return a;
    }
    else
      return(0);
}

/*function size(s: string) : int
Number of characters in s.*/
int t_size(std::string s){
    return s.length();
}

/*function substring(s:string, first:int, n:int) : string
Substring of string s , starting with character first , n characters long. Char-
acters are numbered starting at 0.*/
std::string t_substring(std::string s, int first, int n){
    return s.substr(first,n);
}

/*function concat (s1: string, s2: string) : string
Concatenation of s1 and s2 .*/
std::string t_concat(std::string s1, std::string s2){
    return s1+s2;
}

/*function not(i : integer) : integer
Return (i=0) .*/
int t_not(int i){
    return (i==0);
}

/*function exit(i: int)
Terminate execution with code i .*/
void t_exit(int i){
    exit(i);  
}

