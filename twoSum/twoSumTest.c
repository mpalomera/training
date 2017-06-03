#include <stdio.h>
#include "utest.h"
#include "twoSum.c"

//Given nums = [2, 7, 11, 15]
char * testTwoSum() {
    int nums[] = {2, 7, 11, 15};
    int numsSize = 4;
    int target =  13;

    int *result  = twoSum(nums,numsSize,target); 
    assert_test("result must be [0,2]", result[0] == 0 && result[1] == 2 );
    return NULL;
}

int main() {
    run_test("Test Two Sum",testTwoSum);
    return 1;
}