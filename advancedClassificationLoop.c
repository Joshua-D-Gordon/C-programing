int isPalindrome(int num){
    int tempNum = num;
    
    //if num is a digit hence it is a palindrome number and shall return 1.
    if(0 <= tempNum && tempNum <= 9){
        return 1;
    }
    // the number backwards starts as 0
    int mirroedNum = 0;
    //while number is not zero add to the number backwards the last digit
    while(tempNum != 0){
        int mod = tempNum%10;
        mirroedNum = mirroedNum*10 + mod;
        tempNum = tempNum/10;
    }
    // if the same number return 1 - True else false.
    if(num == mirroedNum){
        return 1;
    } else {
        return 0;
    }

}

int isArmStrong(int num){
    //This Block shall get the n-1 amounts of digits that num has and adds it to count.(giving us (n -1) + 1 = n digits)
    int count = 1;
    int countNum = num;
    while(countNum > 9){
        count++;
        countNum = (countNum - countNum%10)/10;
    }

    int tempNum = num;
    int sum = 0;
    //this while loop shall sum up the (n-1) last digits to the power of n.
    while(tempNum > 9){
        int power = 1 , i;
        int powerNum = tempNum%10;
        //this for loop shall give us the last digit to the power of the n where n is the number of digits in the original number
        for(i = 1; i<= count; ++i){
            power = power*powerNum;
        }
        // adds to sum
        sum += power;
        tempNum = (tempNum - tempNum%10)/10;
        powerNum = powerNum%10;
    }
    // this block add the last remaining digit to the power of n to sum.
    int power = 1, i;
    for(i = 1; i<= count; i++){
            power = power*tempNum;
        }

    sum+= power;
    //if the final sum is eqaul to the original number hence it is an ArmStrong number and returns 1, else 0.
    if(sum == num){
        return 1;
    } else {
        return 0;
    }
}