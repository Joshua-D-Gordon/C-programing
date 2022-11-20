//help function in recursion
int isPlaindromeHelpFunction(int num, int temp){
    
    if(num == 0){
        return temp;
    }
    // shows number backwards
    temp = (temp*10) + (num%10);

    return isPlaindromeHelpFunction(num/10, temp);
}
//calls help function
int isPalindrome(int num){

    if(num == isPlaindromeHelpFunction(num,0)){
        return 1;
    } 
    return 0;
    
}
//help function 
int isArmStrongHelpFunction(int num, int n){
        //if num > 0 power = the last digit to the power of n
        if(num >0){
            int power = 1, i;
            for(i = 1; i<= n; ++i){
                power = power*(num%10);
            }
            //recursuvly return power + helpfunction
            return power + isArmStrongHelpFunction(num/10, n);
        } 
        else {
            return 0;
        }
    
}
// class help funcition
int isArmStrong(int num){
    int count = 1;
    int countNum = num;
    while(countNum > 9){
        count++;
        countNum = (countNum - countNum%10)/10;
    }
    //calls the help funciton with the value num and nums digits as count
    int result = isArmStrongHelpFunction(num, count);
    if(result == num){
        return 1;
    } else {
        return 0;
    }
}

// last commit 12345

