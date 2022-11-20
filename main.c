
#include <stdio.h>
#include "NumClass.h"
int main() 
{ 
    printf("Please type in two positive integers.\n");
    int numberOne, numberTwo;
    scanf("%d\n%d", &numberOne ,&numberTwo);

    int i;
    printf("The Armstrong numbers are: ");
    for(i = numberOne; i<= numberTwo; i++){
        
        if(isArmStrong(i) == 1){
        
            printf("%d ", i);
        }
    }
    printf("\n");
    printf("The Palindromes are: ");
    for(i = numberOne; i<= numberTwo; i++){
        if(isPalindrome(i) == 1){
            
            printf("%d ", i);
        }
    }
    printf("\n");
    printf("The Prime numbers are: ");
    for(i = numberOne; i<= numberTwo; i++){
        if(isPrime(i) == 1){
            
            printf("%d ", i);
        }
    }
    printf("\n");
    printf("The Strong numbers are: ");
    for(i = numberOne; i<= numberTwo; i++){
        if(isStrong(i) == 1){
            
            printf("%d ", i);
        }
    }
    printf("\n");
    

    return 0;

} 
