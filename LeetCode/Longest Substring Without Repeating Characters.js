/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLongestSubstring = function(s) {
    let arr = []
    let answer = 0
    for(let i = 0; i < s.length; i++){
        let c = s[i]
        let idx = arr.indexOf(c)
        if(idx != - 1){
            answer = Math.max(arr.length,answer)
            arr = arr.slice(idx+1)
        }
        arr.push(c)
    }
    answer = Math.max(arr.length,answer)

    return answer
};