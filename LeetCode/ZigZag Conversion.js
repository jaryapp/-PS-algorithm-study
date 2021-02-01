/**
 * @param {string} s
 * @param {number} numRows
 * @return {string}
 */
var convert = function(s, numRows) {
    
    let step = 1
    
    let str = ``
    
    let curIdx = 0
    
    let dir = 0
    
    if(numRows == 1) return s
    
    while(true){
        if(step >= numRows+1) break;
        let c = s[curIdx]
        if(!c){
            step++
            curIdx = step-1
            dir = 0
            continue;
        }
        str += c
        if(step == 1) dir = 0
        else if(step == numRows) dir = 1
        let jump = dir == 0 ? (numRows-step)*2 : (step-1)*2
        curIdx += jump
        dir = (dir+1)%2
        
    }

    return str
    
};