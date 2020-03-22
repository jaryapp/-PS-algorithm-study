'''
*****************************************
 *   DATE       : 2017.12.21
 *   DEVELOPER  : jjj

 *   SITE_NAME  : BAEKJOON Online judge
 *   SITE_URL   : https://www.acmicpc.net
 *   QUIZ_NUM   : 1978
 *   ALGORITM   : PrimeNumber
 *   SCORE      : 
 *   REFERRENCE : http://marobiana.tistory.com/91
*****************************************
'''

import sys


def isPrimeNumber(num):
    
    if(num == 1 or num == 0): return False

    root = int(num**0.5)
    for i in range(2,root + 1):
        if(num % i == 0): return False

    return True

def Main():
    cntNumber = int(input())
    cntPrime = 0
    listNum = list(map(int, input().split()))
    for num in listNum:
        if(isPrimeNumber(num)):
            cntPrime+=1
    
    print(cntPrime)
        





def fileInput():
    value = txt.readline().replace('\n','')
    return value


if __name__ == "__main__" :
    global dev
    dev = ""
    if(sys.argv.__len__() > 1):
        dev = sys.argv[1]
        if dev == "dev":
            global txt
            txt = open("input.txt", "r",encoding='UTF8')
            input = fileInput
    Main()
