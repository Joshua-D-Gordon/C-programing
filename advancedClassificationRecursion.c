int isPlaindromeHelpFunction(int num, int temp){
    
    if(num == 0){
        return temp;
    }
    temp = (temp*10) + (num%10);

    return isPlaindromeHelpFunction(num/10, temp);
}

int isPalindrome(int num){

    if(num == isPlaindromeHelpFunction(num,0)){
        return 1;
    } 
    return 0;
    
}

/*
int isArmStrong(int num){
    //This block counts the n digits of the number
    int count = 1;
    int countNum = num;
    while(countNum > 9){
        count++;
        countNum = (countNum - countNum%10)/10;
    }
    //This block is our base case for recursion where if count = 1 we can be sure we are dealing with a single digit
    if(count == 1){
        return count*num;
    }
    //inizilize sum to 0
    int sum = 0;
    //if count is not 1 - meaning num is not a single digit.
    if(count != 1){
        //for n times
        for(int i = 1; i<= count; i++){
            int x = 1;
            //return the last digit to the power of n and save as x
            for(int j = 1; j<= count; ++j){
                x*=isArmStrong(num%10);
            }
            //move on to second last digit
            num = (num - num%10)/10;
            //before moving on to next loop save current digit to the power of n in sum
            sum += x;
        }
        //if the sum is eqaul to num hence this a an armstrong number return 1. else return 0.
        if(sum == num){
            return 1;
        } else {
            return 0;
        }
    }else {
        if(sum == num){
            return 1;
        } else {
            return 0;
        }
    } 
    
}
*/

int isArmStrongHelpFunction(int num, int n){
        if(num >0){
            int power = 1, i;
            for(i = 1; i<= n; ++i){
                power = power*(num%10);
            }
        
            return power + isArmStrongHelpFunction(num/10, n);
        } 
        else {
            return 0;
        }
    
}

int isArmStrong(int num){
    int count = 1;
    int countNum = num;
    while(countNum > 9){
        count++;
        countNum = (countNum - countNum%10)/10;
    }

    int result = isArmStrongHelpFunction(num, count);
    if(result == num){
        return 1;
    } else {
        return 0;
    }
}

