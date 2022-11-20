


int isStrong(int num){
    int sum = 0;
    int tempNum = num;
    //This while loop shall sum up the (n-1) factorials of each digit where n is the amount of digits in the original number.
    while(tempNum > 9){
        int digit = tempNum%10;
        int digitSum = 1;
        //This for loop factorials the last digit of the number
        for(int i = digit; i> 0; i--){
            digitSum *= i;
        }
        //The factorial digit is then added to sum
        sum += digitSum;
        tempNum = (tempNum - tempNum%10)/10;
    }

    int digitSum = 1;
    //This for loop gives the factorial of the last digit remaining.
    for(int i = tempNum; i> 0; i--){
        digitSum *= i;
    }
    // adds last factorial digit to sum
    sum += digitSum;
    //This if else block returns 1 if the sum is eqaull to the original num , hence this is a Strong number
    // and returns 1, else this is not a Strong number and returns 0.
    if(sum == num){
        return 1;
    } else {
        return 0;
    }
}

int isPrime(int num){
    // This else if block returns 0 if the number is: smaller or eqaul to 1 or an even number thats not 2 (hence the number is not a prime)
    // if the number is exactlly 2 it returns 1 (2 is a prime). this will help us check only odd numbers that can divide the number later on.
    if(num%2 == 0 && num != 2){
        return 0;
    } else if( num == 2 || num == 1){
        return 1;
    } else if (num <= 0){
        return 0;
    }

    //This block finds the sqaure root of the number so we can later on check untill only numbers up to the sqaure root.
    float floatNum = (float)num;
    float temp = 0 , sqrt = floatNum/2;
    while(sqrt != temp){
        temp = sqrt;
        sqrt = (floatNum/temp + temp) / 2;
    }
    //The rounded upper bound sqaure root of the number is stored in sqrtRounded
    int sqrtRounded = (int)sqrt + 1;
    //This for loop, loops for all odd numbers untill the upper bound sqaure root of the number
    //and checks if it can be divided by that number. If so the function returns 0 as this is not a prime number
    // once the for loop finishes and nothing has yet be returned hence this is a prime number.
    for(int i = 3; i<sqrtRounded; i+=2){
        if(num%i == 0){
            return 0;
        }
    }
    return 1;

}

// last commit 12345