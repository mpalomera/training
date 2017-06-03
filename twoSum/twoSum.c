
#include <stdlib.h>
/**
*Given nums = [2, 7, 11, 15], target = 9,
*return [0, 1].
*Because nums[0] + nums[1] = 2 + 7 = 9,
*
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int* twoSum(int* nums, int numsSize, int target) {
    int i,j,partialSum, found = 0;
    int *result;
    for(i=0;i<numsSize;i++){
        partialSum = nums[i];
        for(j=i+i;j<numsSize;j++) {
            if(partialSum + nums[j] == target) {
                found = 1;
                break;
            }
        }
        if(found) {
            break;
        }      
    }
    result = (int *)malloc(sizeof(int) * 2);
    result[0] = i;
    result[1] = j;
    return result;
}