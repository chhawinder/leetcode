/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var map = function(arr, fn) {
    const farr=[];
    for(let i=0;i<arr.length;i++){
        farr[i]=fn(arr[i],i);
    }
    return farr;
};