//comparing char arrays and comparing them as pointers

#include<iostream>
#include <string.h>

using namespace std;
bool compare_strings(char s[], char t[]){
   if( strlen(s) != strlen(t)){
      return false;}
   for( auto i = 0; i<= strlen(s); i++){
      if(!s[i]== t[i]){
         return false;
      }
   return true;  // if we reached the end of the for loop, the strings are identical   
   }
}

main() {
   char s[] = "hello", t[] = "hello";
   char* d = s;
   char g[strlen(s)+1];
   memcpy ( g, s, strlen(s)+1 );
   if(s==d)
      cout<<"equal because point to the same address"<< '\n' << flush;
   if(!(s==g)){
      cout << "not equal because this comparison is checking address"<< '\n' << flush;
   }
   if(compare_strings(s, t)){
      cout<< "equal becuase we compare the sizes and the elements with this function"<< endl;
   }
}